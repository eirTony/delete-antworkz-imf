# Introduction #

AntWorkz provides a powerful Logging Facility that gets smarter as
each AntWorkz library level becomes available.

The LogLib lives above the BaseLib, but below the rest of the core-
and all of the support- and worker-level libraries,
so it does not have access to much of the AntWorkz framework.
There is a behavior mechanism for sending output to different destinations
and formatting output.
So, upper levels of AntWorkz or even other developers using the log
can bring more technology to the table.

TBD: Behavior mechanism for Logger engine it self.

# Library Level Support #

See the AntWorkzLibraries for an explanation of the support available
at each of the three Library Levels: **core**, **support**, and **worker**.

## Core Level ##

### Base Sub-level ###

At the core library level,
the log items reside only in an in-memory queue for the individual process.
Log 'forks' can be started to receive text streams of the log items
as they are processed.
Only basic message formatting (via QVariant::toString()) is available
at the BaseLib core library level.

### Full Sub-level ###

With the full core level library classes are available
(in particular, DataLib: Printable and/or Readable classes),
more sophistication is used in formatting messages.
And, with DataLib: Streamable and/or VarElement classes,
stream (binary or text) and XML file outputs become viable.

## Support Level ##

Switch to base configuration.
Start LogThread.
...

## Worker Level ##

Worker MessageQueue based logging.
Push log items to the cloud.
...

# Fork URLs #

Logging Facility output can be "forked" by adding a named URL.

## URL Breakdown ##

### Anatomy of a URL ###

From Wikipedia derived from RFC3986:

```
foo://username:password@example.com:8042/over/there/index.dtb?type=animal&name=narwhal#nose
\_/   \_______________/ \_________/ \__/            \___/ \_/ \______________________/ \__/
 |           |               |       |                |    |            |                |
 |       userinfo           host    port              |    |          query          fragment
 |    \________________________________/\_____________|____|/ \__/        \__/
scheme                 |                          |    |    |    |          |
name              authority                      |    |    |    |          |
 |                                             path   |    |    interpretable as keys
 |                                                    |    |
 |    \_______________________________________________|____|/       \____/     \_____/
 |                         |                          |    |          |           |
scheme              hierarchical part                  |    |    interpretable as values
name                                                  |    |
 |            path               interpretable as filename |
 |   ___________|____________                              |
/ \ /                        \                             |
urn:example:animal:ferret:nose               interpretable as extension

```

### Scheme Name ###

The scheme name is used to specify the mechanism of output.
Where an IANA-registered scheme it will be used.
If no registered scheme is appropriate, a non-registered one will be used,
with care to avoid using a registered one.

Note: The `file:` scheme could be used on a majority of the output forks,
but it is too generic since different file types require different
output mechanisms.

A few schemes are builtin:

  * stdout - messages are written to stdout
  * stderr - messages are written to stderr
  * txtfile - messages are written to the specified path and file
  * troll - messages are written through QtDebug facility
  * others TBD

### Hierarchical Part ###

The authoritiy part portion of the URL is not likely to be useful
in the built in schemes,
but certainly will be used as log items are sent to the cloud.

The path portion will be used in the `txtfile` builtin scheme
and again will be used as is consistent in other schemes.

### Query ###
