# 006. Vendor Library Recipe

This example builds and links yaml-cpp, a compiled third-party library. The
local `yaml_cpp.hard.h` header contains a `hard.recipe.v1` block that identifies
the GitHub source, CMake options, installed include directory, and static
archive. Including that header is enough to activate the package for this
translation unit.

## Build

```text
$ hard -v build
[1/?] Searching source files
[1/?] Downloading github.com/jbeder/yaml-cpp
[1/?] Building github.com/jbeder/yaml-cpp
[1/?] Parsing example.cpp
[2/4] Compiling example.cpp
[3/4] Linking example
[4/4] Copying example
```

The download is omitted when the source snapshot is cached. A valid cached
package is reported as `Building github.com/jbeder/yaml-cpp (CACHED)`. The
transcript omits CMake, compiler, and linker command details.

## Inspect dynamic dependencies

```text
$ ldd ./example
linux-vdso.so.1 (...)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (...)
/lib64/ld-linux-x86-64.so.2 (...)
```

Load addresses are abbreviated because they vary between runs. The recipe links
`libyaml-cpp.a`, so there is no `libyaml-cpp.so` entry in the dynamic dependency
list.

## Run

```text
$ ./example
answer=42
```

Next: [007. Hard library](../007.hardlib/README.md)
