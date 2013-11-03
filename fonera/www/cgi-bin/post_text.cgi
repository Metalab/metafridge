#!/bin/sh


echo "Content-type: text/html"
echo ""

read $QUERY_STRING
eval $(echo "$QUERY_STRING"|awk -F'&' '{for(i=1;i<=NF;i++){print $i}}')


echo $QUERY_STRING

FUNCTION="\x0$effect"

echo "Saving text..<br>"

# Keep the following line in sync with ./cron_job/send_time.sh
current_time=`date +"%H%M%S"`

scroll_text=`echo $scroll_text | sed 's/%C3%84/Ae/g' | sed 's/%C3%96/Oe/g' | sed 's/%C3%9C/Ue/g' | sed 's/%C3%A4/ae/g' | sed 's/%C3%B6/oe/g' | sed 's/%C3%BC/ue/g' | sed 's/%C3%9F/sz/g'`
scroll_text="`httpd -d $scroll_text`"

# Checking for non-ascii characters
nonascii=$( echo $scroll_text | grep '[^[:print:]]' );
if [ "$nonascii" != "" ]; then
	echo "Sorry, it's not happening.</br>"
	exit 1
fi		
		
has_tux=$( echo $scroll_text | grep -i fosstux );
if [ "$has_tux" != "" ]; then
	#scroll_text="We love Fosstux!";
	exit 1
fi

#killmockingbird=1

if [ "$scroll_text" != "" ]; then
	echo -en "$FUNCTION$scroll_text\r" | sed -rf url_remove.sed_expression > /tmp/lauftext.txt 
	echo "Updating display..<br>"
	
	# We don't want to send the time update to twitter,
	# instead of
	#   cat /tmp/lauftext.txt > /dev/ttyS0
	# I redundantly put:
	echo -en "$FUNCTION$current_time$scroll_text\r" | sed -rf url_remove.sed_expression > /dev/ttyS0

	if [ "$killmockingbird" != "1" ]; then
		echo "Updating <a href="http://twitter.com/metafridge" target="blank">twitter</a>..<br>"
		OLDTEXT=`cat /tmp/oldtext.txt`
		if [ "$scroll_text" != "$OLDTEXT" ]; then
			if [ ${#scroll_text} -gt 140 ]; then
				scroll_text = "${scroll_text:0:137}.."
			fi
			./twit.sh "$scroll_text" &
		fi
		echo $scroll_text > /tmp/oldtext.txt
	else
		echo "Bird gagged.<br>"
	fi
	echo "Done."
fi
