#! /bin/bash

if test "$1" = ""
then
	echo "You must supply a username."
	exit
fi
if test "$2" = ""
then
	echo "You must supply file system search Point start."
	exit
fi
find $2 -user $1
