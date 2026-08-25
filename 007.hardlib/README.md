# 007. Hard Library

This example uses `hard/application/application.h` from the Hard library. The
well-known `hard/` include prefix resolves to
`github.com/hard-build/library`. Hard downloads the repository when needed,
follows the active headers, discovers the required implementation sources, and
links only the reachable objects into the executable.

## Build

```text
$ hard -v build
[1/?] Searching source files
[1/?] Parsing example.cpp
[1/?] Downloading github.com/hard-build/library
[1/?] Parsing example.cpp
[1/?] Parsing github.com/hard-build/library/application/application.cpp
[1/?] Parsing github.com/hard-build/library/module/module.cpp
[2/6] Compiling example.cpp
[3/6] Compiling github.com/hard-build/library/application/application.cpp
[4/6] Compiling github.com/hard-build/library/module/module.cpp
[5/6] Linking example
[6/6] Copying example
```

The download line is absent when the library source is already cached. This is
an abridged transcript without verbose compiler and linker command lines;
independent steps can complete in a different order.

## Inspect dynamic dependencies

```text
$ ldd ./example
linux-vdso.so.1 (...)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (...)
/lib64/ld-linux-x86-64.so.2 (...)
```

Load addresses are abbreviated because they vary between runs. The required
Hard library sources are compiled into the executable and do not add a shared
library to this list.

## Run

```text
$ ./example
on_init
on_broadcast application.stage = start
on_tick 1
on_tick 2
on_tick 3
on_broadcast example.complete = three ticks completed
on_broadcast application.stage = stop
```

The application initializes the module, ticks until the third update, broadcasts
its completion event, and then stops.

Back to the beginning: [001. Hello World](../001.helloworld/README.md)
