#! /bin/bash

trap 'rm /tmp/my_tmp_file_$$' INT

echo creating file /tmp/my_tmp_file_$$
date > /tmp/my_tmp_file_$$

while [ -f /tmp/my_tmp_file_$$ ]
do
    echo file exist
    sleep 1
done

echo file no longer exist
echo creating file /tmp/my_tmp_file_$$
date > /tmp/my_tmp_file_$$

trap INT

while [ -f /tmp/my_tmp_file_$$ ]
do
    echo file exist
    sleep 1
done

echo we nerver get here

exit 0
