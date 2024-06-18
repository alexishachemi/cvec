# CVEC

### Fixed sized arrays ... no longer fixed ?

CVEC (C VECtors) is a simple wrapper for heap allocated arrays in C allowing for easy and seamless dynamic resizing. It handles generic types (void pointers) so access macros are also provided for simplifying the use of the library.

It is developped for use in my epitech projects so the source code abide to the epitech coding-style rules.

## Dependencies

- [GNU Compiler Collection](https://gcc.gnu.org/) (11.4.0+)
- [GNU Make](https://www.gnu.org/software/make/) (4.3+)
- [Criterion](https://github.com/Snaipe/Criterion) (2.4.2) (for unit tests)

## Building

to build the library you can use the included Makefile:

```sh
make
```

It will then build the `libcvec.a` binary.

## Installing

Custom Makefile rules (`install`, `uninstall`, `reinstall`) can be used to manage installation of the library in your system:

```sh
sudo make install
```

Note that you'll need root access to execute those rules.

## Usage

Once installed or built, you can use the library by including the library header in your source files:

```c
#include <cvec.h>
```

and add the library to the linker when compiling:

```sh
gcc myfile.c -lcvec
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
