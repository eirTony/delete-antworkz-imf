# Introduction #

Worker classes derived from WorkLib:AbstractWorker
have a short lifespan.
They are created, provided with a current configuration
and input data and are expected to provide results
then fizzle into history.

The worker machine maintains in-memory work contexts for use
by its workers.
They are basically read only, but a few circumstances
call for writing to a context.
These will be discussed below **(Characteristics)** followed by example
contexts noting each one's characteristic.

In theory a worker only needs configuration values and input data
to compute and output its results.
Sometimes practically gets in the way of theory.
This is where the worker context concept comes to the rescue.

A worker context is a chunk of data that requires a lot of
resources, either too large to pass with each message
or computationally complex to be recalculated for each unit of work.

Back to theory v. reality:
In theory any worker machine on the network
should be able to handle any work message that comes along.
In reality we would like to already have any needed contexts
loaded in the machine handling the messages.
So, the Dispatchers keep track of what machines
have what contexts loaded already
as well as the machine's current work load.

Normally, the Dispatchers would send the work message
to the machine that has the needed contexts with the
lightest work load.
If no suitable machine is available, the Dispatcher will
tell the least loaded machine to load the needed context.
If a machine is approaching a memory crisis,
it can drop one or more loaded contexts,
weighing factors including:
  * the amount of memory that would be freed
  * the difficulty of reloading the context
  * which context was first used last

If a Dispatcher finds that it is consistently blocking
on a context, it can ask The Cloud to assign another
droplet for a new Machine pre-loaded with the Context.
Conversely, if a dispatcher finds it has a lot of idle hands,
Machines can be shutdown and their droplets returned to The Cloud.
This system should eventually be self balancing,
yet responsive to ebbs and flows of incoming work
while making judicious use of droplets.


# Characteristics #

| **CharCode** | **Name** | **Description** |
|:-------------|:---------|:----------------|
| FixedRO | Fixed Read Only | Will not change during the life of machine |
| SubRO | Subscriber Read Only | Worker will not change; machine may change based upon message from Publisher |
| PubWO | Publisher Write Only | TBD whether these will be contexts |
| Mirror | Publisher's Mirror |  TBD whether these will be contexts |
| Update | Periodic Update Read/Write | Statistics collector (See Note 1 for example) |
| Reversed | Reversed Write/Read | Worker writes, machine reads and forwards |

# Contexts #

## INDI 2nd Generation ##

| **CharCode** | **Description** | **Characteristic CharCode** |
|:-------------|:----------------|:----------------------------|
| Vectors | Vector sets for face matching | SubRO |
| EnrIBase | Enrollment keys and INDIbase write cache (Note 2) | PubWO |
| EnrIMage | Image keys and INDIbase write cache (Note 2 also) | PubWO |
| IfLayers | INDIface layers | FixedRO |
| PerfStat | Performance Statistics | Update |
| LogFork | Write cache feeding cloud-based logging facility | Reversed |

# Notes #

1. Example for Update contexts: Gathering frame performance statistics.
At machine start, context retrieves current totals and averages.
When a worker finishes, its results are accumulated.
On a periodic timer, the machine sends the collected results, updates its totals from the publisher, and zeros its collected stats.
On machine shutdown, any last collected stats are sent to the publisher.

2. Multiple databases machines can write to the same database by segmenting
the keys allocated to each writer machine.