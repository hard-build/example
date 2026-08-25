# 005. External Header-Only Library

This example includes nlohmann/json through its public GitHub path. When the
header is missing, Hard downloads a snapshot of `github.com/nlohmann/json` into
its shared source cache, repeats dependency analysis, and then builds the
program. The project needs no package-manager or build-file entry for this
header-only dependency.

## Build

```text
$ hard -v build
[1/?] Searching source files
[1/?] Parsing example.cpp
[1/?] Downloading github.com/nlohmann/json
[1/?] Parsing example.cpp
[2/4] Compiling example.cpp
[3/4] Linking example
[4/4] Copying example
```

The download line is absent when the repository is already cached. This
abridged transcript also omits verbose compiler and linker command lines.

## Inspect dynamic dependencies

```text
$ ldd ./example
linux-vdso.so.1 (...)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (...)
/lib64/ld-linux-x86-64.so.2 (...)
```

Load addresses are abbreviated because they vary between runs. nlohmann/json
is header-only, so it does not add a shared-library dependency.

## Run

The program expects the path to a JSON document:

```text
$ ./example example.json
{
    "app": {
        "debug": false,
        "name": "MyApp",
        "version": "1.0.0"
    },
    "database": {
        "host": "localhost",
        "port": 5432,
        "user": "admin"
    },
    "features": {
        "darkMode": true,
        "notifications": true
    }
}
```

Next: [006. Vendor library recipe](../006.vendor_library/README.md)
