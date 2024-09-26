# Contributing

Thanks for sharing interest in developing Result!

## How you can help?
    - Find a new bug and report it
    - Pick a bug, fix it and submit a Pull Request
    - Choose a feature you want implemented and submit a issue (or implement it!)
    - Share the repository

## Building
Refer to the **INSTALL.md** file at the root of the repository.

## Coding style
This project uses the [Mozilla C++ Coding style](https://firefox-source-docs.mozilla.org/code-quality/coding-style/index.html).
Before commiting to the repository please run clang-format to format all changes to the codebase:
```
find -name '*.[ch]' -exec clang-format -i --style=Mozilla {} \;
```
(Aliased to ```format-code``` in the Nix shell)
