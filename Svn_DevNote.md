# Introduction #
This developer note describes the structure of the AntWorkz Image Machine Framework project in its Subversion repository.


# Hosting & Access #

The source code for AntWorkz is hoted in a Subversion repository by Google's Code service.

To view the project in progress visit https://code.google.com/p/antworkz-imf via your web browser.

To download a snapshot of the source code, run a SVN export from ...TBD...

To setup a live Subversion directory on your system, create one from ...TBD.here....

If you are an authorized developer you will need to provide your assigned
user name and your selected password at the above link.

# Top Level #

As with most typical Subversion repository, the top level is segregated into three sections:

  * **trunk** - Where most of the (stable) action resides.

  * **branches** - Where the nitty-gritty work progresses between these major branches.
    * **develop** - The near-wild-wild west
    * **current** - Where "letter" builds land for early testing and evaluation
    * **release** - Where a potential public release transitions from Alpha to Beta
to Candidate and hopefully to Final release.
    * **master** - Public releases.

  * **tags** - Snapshots taken from the trunks to preserve sets of source code changes.
    * **dev+build1001** - When codesets transition from develop to current,
> > the build number is incremented.
    * **cur+v2.02F** - When a codeset arrives at current, it is assigned the next
> > 'letter' version.
    * **rel+v2.02-Alpha** - As pre-release testing takes place when semi-public
> > test and evaluation releases take place.
    * **mst+v2.02-Final** - Master codesets are tagged here.
> > Typically post-release patches (custom[er](er.md)) and hotfixes
> > branch from here.
