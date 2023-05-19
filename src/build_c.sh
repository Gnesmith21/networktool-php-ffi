#!/bin/sh
echo "Building _nettools.so by Gavin Nesmith"
gcc -c -Wall -Werror -fpic _nettools.c
gcc -shared -o ../tests/_nettools.so _nettools.o
echo "Done building _nettools.so"
