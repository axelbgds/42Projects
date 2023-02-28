#!/bin/sh

find . -name "*.c" -depth 1 -exec gcc -c {} \;
ar -rc libft.a *.o
rm *.o
