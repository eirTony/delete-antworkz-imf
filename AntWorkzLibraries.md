# Introduction #

The AntWorkz Project libraries are divided into three levels:

  * core - The foundation for the libraries above.
  * support - The libraries that support building executable binaries, in particular the Titan Worker Machine service.
  * worker - The libraries that get the work done.


# Details #

  * Core level libraries
    * QuickLib - Performs quick unit tests on any library with no dependencies.
    * BaseLib - Any classes needed to prevent circular dependencies in the core level.
    * LogLib - High-level logging facility.
    * TypeLib - Typedefs, substitutions for Qt5 classes, etc.
    * DataLib - Data conversion classes.
    * KidLib - Key, Id, Description management.
    * CoreLib - Design Pattern implementation classes or templates.
  * Support level libraries
    * VarLib - Management of named values with defaults and collections there of.
    * CfgLib - Management of multi-layer configurations.
    * ResLib - Management of result values and messages.
    * SysLib - System dependent support in a non-dependent way.
    * ExeLib - Support for any executable.
  * Worker level libraries
    * MsgLib - Support for the creation, encoding, transmission, queueing, and interpretation of messages.