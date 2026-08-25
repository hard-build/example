# 001. Hello World

This example introduces the smallest useful Hard project: one C++ source file
and no project build file. Hard finds `example.cpp`, compiles it, detects
`main`, links the executable, and places `example` beside the source.

## Install Hard

On Linux x86-64, install the latest release without `sudo`:

```bash
curl -fsSL https://raw.githubusercontent.com/hard-build/hard/main/install.sh | sh
```

Open a new shell, or follow the `PATH` instruction printed by the installer,
then check the installation:

```bash
hard --help
```

## Build

Run the build from this directory:

```text
$ hard -v build
[1/?] Searching source files
[1/?] Parsing example.cpp
[2/4] Compiling example.cpp
[3/4] Linking example
[4/4] Copying example
```

This is an abridged first-build transcript. Later builds can append `(CACHED)`
to unchanged steps. Verbose compiler and linker command lines are omitted here.

## Inspect dynamic dependencies

```text
$ ldd ./example
linux-vdso.so.1 (...)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (...)
/lib64/ld-linux-x86-64.so.2 (...)
```

Load addresses vary between runs and are abbreviated as `...`. Hard's default
linker flags link the GCC and C++ runtimes statically, so they do not appear in
this list.

## Run

```text
$ ./example
Hello, world!
```

Next: [002. Internal library](../002.internal_library/README.md)
