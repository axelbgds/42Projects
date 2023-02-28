#!/bin/sh
find . -type f | git check-ignore --stdin | cut -d'/' -f2- | sort