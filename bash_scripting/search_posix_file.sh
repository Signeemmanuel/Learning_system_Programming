#! /bin/bash

: '
This script looks throught all files in the current directory for the 
string POSIX, and print the names of all those files to standard Output'


for file in *
do
	if grep -Hh POSIX $file
	then
		more $file
	fi
done

exit 0
