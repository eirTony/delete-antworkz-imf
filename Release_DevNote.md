# Introduction #

This note will provide a series of steps to promote a source code-base
from develop to release branch.

# Details #

# SVN switch to develop branch, ensure it compiles and tests at the start.

# For each active development branch:

  1. SVN switch to the branch, ensure it compiles and tests at the start.

  1. SVN switch back to develop branch.

  1. SVN merge the branch into develop branch. [Note: Do not commit at this point.]

  1. Attempt to edit all conflicts to resolve them
    * If the conflicts become to difficult, cancel the merge and SVN revert back to develop.

  1. Make develop+branch rebuild compile and test correctly.
    * If the compile or test errors become too difficult SVN revert back to develop.

[Note: If at this point you are reverting more than committing,
consider abandoning this release.]

  1. SVN commit the develop changes from this branch.