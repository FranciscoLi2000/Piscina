#!/bin/sh

#cat /etc/passwd | grep -v '^#' | awk 'NR%2==0' | 
#	cut -d: f1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' '*' | 
#	sed 's/\*$//' | sed 's/^/*/' | sed 's/$/*/'


#cat /etc/passwd | grep -v '^#' | awk 'NR%2==0' | 
#	cut -d: -f1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | paste -sd '*' - | sed 's/$/*/'

cat /etc/passwd | grep -v '^#' | sed -n 'n;p' | cut -d ':' -f 1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | paste -s -d ',' - | sed 's/,/, /g' | sed 's/$/./'
