#!/bin/sh

current_time=`date | awk '{ print $4 }' | awk -F : '{ print $1$2$3 }'`
echo -en "\x10$current_time\r" > /dev/ttyS0
