# Introduction #

...


# Etiquette #

...

## First Rule ##

...

## Check-in Standards ##

...

# Documentation #

...

## Doxygen ##

...

### Block Comment Format ###

Use `/*!` Doxygen trigger in the first column
and close with ` *\` (the star in the same column as the trigger).
The ` * ` in subsequent lines is optional,
but it is easier to keep it in QtCreator editor.
The block comment should touch the bottom of the entity that it relates to,
but a blank line below.
If it is a stand alone block comment it should have a blank line top and bottom.
```
/*! @file Logger.h LogLib Logger class definitions
 */
#include "LogLib.h"
class Logger
{
public:
    Logger(void);
...
}
/*! @class Logger Logger.h <log/Logger.h>
 * @brief Engine for Logging Facility
 * @ingroup LogLib
 *
 * Detailed description ...
 *
 */
```

### Lineend Comment Format ###

...

### Minimum ###

The following elements are considered to provide minimal Doxygen support:
  * `@file` for every .cpp and .h source code file
  * `@defgroup` for the .h file for each library class file
  * `@class ClassName.h <dir/ClassName.h>` for every class with basic usage and including these tags
    * `@ingroup`
    * `@since` and `@date` for timeline important documentation
    * `@bug` as needed to document suspected bugs or point to a tracked issue
    * `@remark` as needed to document unique algorithms, explain special situations, or needed warnings
    * `@todo` functionality that needs to be completed, but is not documented by **DO log messages**


### Secondary ###

...

### Fully ###

...

## Wiki ##

...

# Style #

## Classes ##

### Friends ###

We allow use of friend classes and functions, within reason.

Friends should usually be defined in the same file
so that the reader does not have to look in another file to find
uses of the private members of a class.
A common use of friend is to have a FooBuilder class be a friend of Foo
so that it can construct the inner state of Foo correctly,
without exposing this state to the world.
In some cases it may be useful to make a unittest class
a friend of the class it tests.

Friends extend, but do not break, the encapsulation boundary of a class.
In some cases this is better than making a member public
when you want to give only one other class access to it.
However, most classes should interact with other classes solely
through their public members.

_Blatently stolen from Google C++ Style Guide._

== Qt Specific

=== Q\_OBJECT

_In all QObject derived classes, use the Q\_OBJECT directive_.

Myth holds that you only need it to support signal/slot
and/or properties (via Q\_PROPERTY).
Even if this was true, it would pay to automatically include
the directive, so that you don't forget to add it when
you later decide to add signal/slot mechanism.

However, the key benefit of including Q\_OBJECT is that
your class automatically becomes a part of the Qt MetaData ecosystem.

=== Subclassing Qt Classes

When subclassing Qt classes, you should have the goal of extending
the capability or improving usability or consistency with your
other classes. Strive for a truly _drop-in replacement_.

  * Be prepared to provide all of the constructors that are provided by Qt.
(You don't have to code all of them up front.)

  * Don't change known behavior.
