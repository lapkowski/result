# Installing Result

## Compilation flags
    - shared_library (enabled/disabled) - compile the shared library
    - static_library (enabled/disabled) - compile the static library

## Unix-like (Linux, MacOS, \*BSD, Cygwin, ...)

### Dependencies:
    - Meson
    - Ninja
    - A C compiler (GCC or Clang)

### Installing:
Replace \<build directory\> with your desired build directory.

```
meson setup <build directory>
(sudo) meson install -C <build_directory>
```

You can pass the $CC enviroment variable to meson setup to choose your desired C compiler.
You can pass the $DESTDIR enviroment variable to meson install to choose your desired destination directory.

## Windows

### Dependencies:
    - Meson
    - Ninja
    - Visual Studio 2015+ (Community)

### Installing:
Replace \<build directory\> with your desired build directory.

Run these commands at the root of the repository with administrative privilages.

```
meson setup <build directory>
meson install -C <build directory>
```
