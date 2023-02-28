#!/bin/sh
find . -name '*.sh' -type f | rev | cut -d'/' -f1 | cut -d'.' -f2- | rev