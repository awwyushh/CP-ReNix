{
  description = "C++ Competitive Programming Re:Nix-ified";
  author = "Ayush Shukla";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachSystem [ "x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin" ] (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        devShells.default = pkgs.mkShell {
          packages = with pkgs; [
            gcc # C++ Compiler (or use clang)
            cmake # Build system generator
            gdb   # GNU Debugger
            clang-tools_unstable.clang-format # Code formatter
          ];

          shellHook = ''
            # --- CLEANUP START ---
            make clean || true  # Clean build directory (using Makefile clean target)
            rm -rf input        # Remove input directory
            mkdir -p input       # Recreate input directory (empty)
            # --- CLEANUP END ---

            mkdir -p build  # Ensure build directory exists

            echo "-------------------------------------------------------"
            echo "  Competitive Programming Environment Ready!"
            echo "-------------------------------------------------------"
            echo "  - Compile (Make): make"
            echo "  - Compile (Direct): g++ src/main.cpp -o build/main"
            echo "  - Run (Make):     make run"
            echo "  - Run (Direct):     build/main < input/input.txt"
            echo "  - Format:  make format"
            echo "  - Clean Build: make clean"
            echo "  - Input:   Place input in 'input/input.txt' (or similar)"
            echo "-------------------------------------------------------"
          '';
        };

        templates.default = {
          path = ./template;
          description = "Basic C++ Competitive Programming Template";
        };
      }
    );
}