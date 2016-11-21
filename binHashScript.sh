#!/bin/bash

clear
cd /bin
echo "Ok, Started..."

touch /tmp/whilelist.txt
truncate -s 0 /tmp/whilelist.txt   #RIght now I have given the absolute path. Should be modified

for file in *
do
        #echo "$file"  
        sha1sum "$file" | cut -f 1 -d " " >> /tmp/whilelist.txt
done

echo "Finished, hit enter to cat the file"
read

cat /tmp/whilelist.txt
