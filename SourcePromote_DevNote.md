# Introduction #

This note will provide a series of steps to promote a source code-base
from a development branch to the develop branch, from develop to current,
from current to release, and finally from release to trunk (master).

# Top Level Branches #

## develop ##

The `develop` branch is the active branch shared by
the entire development team.
The bulk of active development takes place in issue
branches from this branch.
Development branches are named starting with `dev+`... ,
for example `SVN/branches/dev+IB0019-NumUno`
is a branch from `develop` to implement [Issue #19](https://code.google.com/p/antworkz-imf/issues/detail?id=#19)
with a short decription of the issue "Console Numero Uno".

It is expcted that updates to the shared `develop` branch
will be merged into longer issue branches and therefor
merged back into `develop` periodically (weekly)
while recognizing that merges into develop must
rebuild without incident and pass basic unit
and acceptance tests.

Changes that occur directly in develop branch
also must pass develop-level testing
and are generaly considered minor in nature, such as:
  * updates to internal doxygen documentation
  * cosmetic changes to source code structure or string coonstants
  * low risk quick fixes while reintegrating multiple developmental branches

## current ##

...

## release ##

...

## trunk ##

...

# Steps #

...

## To develop ##

  1. For each active development branch (or a specific if desired):

  1. SVN switch to the development branch, ensure it compiles and tests at the start in release mode.

  1. SVN merge develop into the development branch

  1. Attempt to edit all conflicts to resolve them

  1. Make develop+branch rebuild compile and test correctly.


  1. SVN merge develop into branch. Test. Fix.

  1. SVN merge the branch into develop branch. [Note: Do not commit at this point.]

  * If the merge, compile, or test errors become too difficult SVN revert back to the current develop branch.

[Note: If at this point you are reverting more than committing,
consider abandoning this release.]

  1. SVN commit the develop changes from this branch.