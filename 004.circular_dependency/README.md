# 004. Circular Dependency

This example has mutually dependent `component` and `container` headers. Hard
analyzes the active include graph, generates source-specific forward context,
discovers both matching implementation files, and links their objects into the
program without a hand-written source list.

## Build

```text
$ hard -v build
[1/?] Searching source files
[1/?] Parsing component/component.cpp
[1/?] Parsing container/container.cpp
[1/?] Parsing example.cpp
[2/6] Compiling component/component.cpp
[3/6] Compiling container/container.cpp
[4/6] Compiling example.cpp
[5/6] Linking example
[6/6] Copying example
```

The transcript is abridged and omits verbose compiler and linker commands.
Independent steps can complete in a different order; cached steps are marked
`(CACHED)` on later builds.

## Inspect dynamic dependencies

```text
$ ldd ./example
linux-vdso.so.1 (...)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (...)
/lib64/ld-linux-x86-64.so.2 (...)
```

Load addresses are abbreviated because they vary between runs.

## Run

```text
$ ./example
[100, 200, 300]
```

Next: [005. External header-only library](../005.external_library/README.md)
