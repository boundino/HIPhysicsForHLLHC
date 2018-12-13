#!/bin/bash

mkdir -p plots

g++ drawTheory.C $(root-config --libs --cflags) -g -o drawTheory.exe || exit 1
./drawTheory.exe

rm drawTheory.exe
