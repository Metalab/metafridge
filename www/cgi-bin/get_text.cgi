#!/bin/sh

echo "Content-type: text/plain"
echo ""
touch /tmp/lauftext.txt
#cat /tmp/lauftext.txt  | grep -v -e "^$"  | grep -v -e "^w"  | sed  's/</\&lt;/g' |  sed  's/>/\&gt;/g' |  sed  's/\//\&frasl;/g'
cat /tmp/lauftext.txt
