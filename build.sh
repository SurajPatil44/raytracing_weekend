#!/bin/sh

set -xe



##CFLAGS="-Wall -Wextra -std=c11 -Werror -pedantic -ggdb -v"
CPPFLAGS="-Wall -Wextra -std=c++17 -Werror -pedantic -ggdb -v"


SRC="main.cpp"

DST="./build/Debug/main"


g++ $CPPFLAGS -o $DST $SRC -lm -I.  #vec3.h color.h 

#rm -rf objects

