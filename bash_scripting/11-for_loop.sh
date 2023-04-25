#! /bin/sh

echo "Print the names of all file ending with .sh in the current working director"

for file in $(ls *.sh)
do
    echo $file
done
exit 0