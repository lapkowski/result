{ pkgs ? import <nixpkgs> {} }:
    pkgs.mkShell {
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
