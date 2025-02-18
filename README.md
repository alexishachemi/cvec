# CVEC

### Fixed sized arrays ... no longer fixed ?

CVEC (C VECtors) is a simple wrapper for heap allocated arrays in C allowing for easy and seamless dynamic resizing. It handles generic types (void pointers) so access macros are also provided for simplifying the use of the library.

## Dependencies

CVEC is a header-only library that only uses the standard C library, so there is no dependencies needed, just intergrate it to your project when building it.

However, if you wish to build the example file or run the unit tests, you'll need the following:

- [GNU Compiler Collection](https://gcc.gnu.org/) (11.4.0+)
- [GNU Make](https://www.gnu.org/software/make/) (4.3+)
- [Criterion](https://github.com/Snaipe/Criterion) (2.4.2)

## Installing

Custom Makefile rules (`install`, `uninstall`, `reinstall`) can be used to manage installation of the library in your system:

```sh
sudo make install
```

Note that you'll need root access to execute those rules.

## Usage

You can use the library by including the library header in your source files:

```c
#include <cvec.h>
```

For more information about how to use the library, see the [example file](example/example.c). It explains the functions of the library. You can also build the example program using:

```sh
make example
```

## Development

You can then compile and/or run the unit tests using the following commands:

```sh
make unit_tests
```
```sh
make tests_run
```
