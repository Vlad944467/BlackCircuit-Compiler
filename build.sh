#!/bin/bash
mkdir -p bin
gcc -o bin/bcc src/main.c src/compile.c -Isrc/include