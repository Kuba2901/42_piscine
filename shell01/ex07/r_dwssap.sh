#!/bin/sh

cat /etc/passwd | grep '^[^#]'| sed -n 'n;p' | cut -d ":" -f1 | rev | sort -r | sed -n "$FT_LINE1","$((FT_LINE2+1))"p | tr '\r\n' ', ' && echo "."
