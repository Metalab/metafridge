#!/bin/sh

# Debug
#set -x

# Obtain all access secrets from dev.twitter.com/apps
CKEY=""
CSECRET=""
AKEY=""
ASECRET=""
 
HTTP_POST="curl -s --data"
  
Encode()
{
string=$1; format=; set --
while
  literal=${string%%[!-._~0-9A-Za-z]*}
  if [ -n "$literal" ]; then
    format=$format%s
    set -- "$@" "$literal"
    string=${string#$literal}
  fi
  [ -n "$string" ]
do
  tail=${string#?}
  head=${string%$tail}
  format=$format%%%02X
  set -- "$@" "'$head"
  string=$tail
  done
printf "$format\\n" "$@"
}

Fastencode() {
  echo "$1" | sed 's/ /%20/g;s/!/%21/g;s/"/%22/g;s/#/%23/g;s/\$/%24/g;s/%/%25/g;s/\&/%26/g;s/'\''/%27/g;s/(/%28/g;s/)/%29/g;s/:/%3A/g;s/=/%3D/g'
}

GenerateHash()
{
EURL="`Encode $2`"
EPARAM="`Encode $3`"
QUERY="$1&$EURL&$EPARAM"
HASH="`echo -n \"$QUERY\" | openssl sha1 -hmac \"$CSECRET&$ASECRET\" -binary | openssl base64`"
Encode "$HASH"
} 

Geolocate() {
if [ ${$REMOTE_ADDR:0:7} != "10.20.3" ]
then
  LOC="`curl -s "http://freegeoip.net/csv/$REMOTE_ADDR"`"
  LND="`echo $GEO | cut -d, -f3 | sed -e 's/^"//' -e 's/"$//'`"
  STD="`echo $GEO | cut -d, -f6 | sed -e 's/^"//' -e 's/"$//'`"
  LAT="`echo $LOC | cut -d, -f8 | sed -e 's/^"//' -e 's/"$//'`"
  LNG="`echo $LOC | cut -d, -f9 | sed -e 's/^"//' -e 's/"$//'`"
  if [ "$LND" != "Reserved" ] && [ "$LAT" != "0" ] && [ "$LNG" != "0" ]
  then
    echo "display_coordinates=true&geo_enabled=true&lat=$LAT&long=$LNG&"
  else
    echo ""
  fi
else
  echo ""
fi
}          
                      
UpdateTimeLine()
{
TWEET="`Encode \"$@\"`"
if [ "$TWEET" == "" ]
then
 echo "can not decode tweet" >&2
 exit 1
fi

URL="http://api.twitter.com/1.1/statuses/update.json"
NONCE="`dd if=/dev/urandom bs=1024 count=1 2>/dev/null | md5sum | cut -c1-32`"
PARAM="`Geolocate`oauth_consumer_key=$CKEY&oauth_nonce=$NONCE&oauth_signature_method=HMAC-SHA1&oauth_timestamp=`date +%s`&oauth_token=$AKEY&oauth_version=1.0&status=$TWEET"
HASH="`GenerateHash \"POST\" \"$URL\" \"$PARAM\"`"

XML="`$HTTP_POST \"$PARAM&oauth_signature=$HASH\" \"$URL\"`"
if [ "$XML" == "" ]
then
 echo "can not post tweet" >&2
 exit 1
#else
# echo "$XML"
fi
}

UpdateTimeLine "$@"
