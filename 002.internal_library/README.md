# 002. Internal Library

This example shows how Hard discovers project implementations from active
includes. Both `reader.cpp` and `writer.cpp` include `common/object.h`; Hard
finds the matching `common/object.cpp`, compiles it once, and links it into two
independent executables. No library target or project build file is required.

## Build

```text
$ hard -v build
[1/?] Searching source files
[1/?] Parsing common/object.cpp
[1/?] Parsing reader.cpp
[1/?] Parsing writer.cpp
[2/8] Compiling common/object.cpp
[3/8] Compiling reader.cpp
[4/8] Compiling writer.cpp
[5/8] Linking reader
[6/8] Copying reader
[7/8] Linking writer
[8/8] Copying writer
```

The transcript is abridged: verbose compiler and linker commands are omitted.
Independent steps can complete in a different order, and unchanged steps can
be marked `(CACHED)` on later builds.

## Inspect dynamic dependencies

Both entry sources produce a binary:

```text
$ ldd ./reader
linux-vdso.so.1 (...)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (...)
/lib64/ld-linux-x86-64.so.2 (...)

$ ldd ./writer
linux-vdso.so.1 (...)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (...)
/lib64/ld-linux-x86-64.so.2 (...)
```

Load addresses are abbreviated because they vary between runs.

## Run

```text
$ ./reader
Hello, reader!

$ ./writer
Hello, writer!
```

Next: [003. Unit tests](../003.unittest/README.md)
