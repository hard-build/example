# 003. Unit Tests

This example combines a normal program with a GoogleTest source. `hard build`
selects `example.cpp` and ignores `random.test.cpp`; `hard test` discovers,
builds, and runs the test separately through `gtest_main`.

## Build the program

```text
$ hard -v build
[1/?] Searching source files
[1/?] Parsing example.cpp
[2/4] Compiling example.cpp
[3/4] Linking example
[4/4] Copying example
```

The transcript is abridged and omits verbose compiler and linker command lines.
Unchanged steps can be marked `(CACHED)` on later builds.

## Run the test

```text
$ hard -v test
[1/?] Searching source files
[1/?] Parsing random.test.cpp
[2/4] Compiling random.test.cpp
[3/4] Linking random.test
[4/4] Testing random.test
[==========] Running 1 test from 1 test suite.
[ RUN      ] random.get
[       OK ] random.get (0 ms)
[  PASSED  ] 1 test.
```

`hard test` creates its test executable in Hard's build tree instead of copying
it into the project directory.

## Inspect dynamic dependencies

```text
$ ldd ./example
linux-vdso.so.1 (...)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (...)
/lib64/ld-linux-x86-64.so.2 (...)
```

Load addresses are abbreviated because they vary between runs.

## Run the program

```text
$ ./example
rnd: 42
```

Next: [004. Circular dependency](../004.circular_dependency/README.md)
