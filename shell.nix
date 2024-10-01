{ pkgs ? import <nixpkgs> {} }:
    pkgs.mkShell {
        shellHook = ''
            format-code() {
                find -name '*.[ch]' -exec clang-format -i {} \;
            }
        '';
        nativeBuildInputs = with pkgs.buildPackages; [
            meson
            pandoc
            clang
            glibc
            gcc
            ninja
            pkg-config
        ];
    }
