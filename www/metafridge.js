/******************************************************************************
* Metafridge HTML client copy(l)eft hmw
*******************************************************************************
* TODO
*	- Default: Enter --> Normal Speed
*	- Default button emphazised
*	- Time
*	- Temperature (History)
*	! noscript - should work
*	- get rid of all german identifiers (scroll_text)
*	! Do not resize livestream_img in browser
******************************************************************************/


///////////////////////////////////////////////////////////////////////////////
//
//  Set DISABLE_TWITTER=1 to prevent posting messages.
//
DISABLE_TWITTER=0


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Helper Functions
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

var $ = function(id) {	// shortcut for document.getElementById(id)
	if (id == 'html') {
		return document.getElementsByTagName('html')[0];	// There is only one
	}
	else if (id == 'body') {
		return document.getElementsByTagName('body')[0];	// There is only one
	}
	else {
		return document.getElementById( id );
	}
}


// Prevent console log calls from crashing the program, when there is no console
if (typeof console == "undefined" || typeof console.log == "undefined") var console = { log: function() {} }


function AddEvent( element, event_name, event_function )
{
//console.log( element.toString() + '.addEventListener(' + event_name + ', ' + typeof(event_function) + ')' );
	if (element.attachEvent)				 // Internet Explorer
	{
		element.attachEvent( "on" + event_name, function() {event_function.call(element);} );
	}
	else if (element.addEventListener)	// Rest of the world
	{
		element.addEventListener(event_name, event_function, false);
	}
}


function AjaxRequest( new_url, new_onreceive )
{
	//debug.log('AjaxRequest(' +new_url+ ')');

	var self = this;
	this.url = new_url;

	this.onreceive;
	if (new_onreceive) {
		this.onreceive = new_onreceive;
	}

	var http = get_http_object();
	function get_http_object() {
		var http_obj;

		// Special IE only code
		/*@cc_on
		@if (@_jscript_version >= 5)
			try { http_obj = new ActiveXObject("Msxml2.XMLHTTP"); }
			catch (e)
			{  try { http_obj = new ActiveXObject("Microsoft.XMLHTTP"); }
				catch { (E) xmlhttp = false; }
			}
		@else
			http_obj = false;
		@end @*/

		// Every other browser on the planet
		if (!http_obj && typeof XMLHttpRequest != 'undefined') {
			try { http_obj = new XMLHttpRequest(); }
			catch (e) { http_obj = false; }
		}
		return http_obj;
	}


	// Request response
	this.poll = function() {
		http.open( 'GET', self.url, true );
		http.onreadystatechange = self.receive;
		http.setRequestHeader( 'Content-Type', 'application/x-www-form-urlencoded' );
		http.send( null );
	}

	// Process response
	this.receive = function() {
		if (http.readyState != 4)
/*
0: request not initialized
1: server connection established
2: request received
3: processing request
4: request finished and response is ready
*/			return;

		if (self.onreceive) {		  // Is there a user defined onreceive method?
			self.onreceive( http );
		}

	} // receive
	
	// Constructor
	if (new_onreceive == undefined) {
		self.poll();
	}
} // AjaxRequest();


function show_old_text()
{
	new AjaxRequest( '/cgi-bin/get_text.cgi', function(request) {
		$('scroll_text').value = request.responseText.substr(1);
		$('scroll_text').focus();
		$('scroll_text').select();
	}).poll();
}

function button_onclick_handler(effect)
{
	var target = $('textform').action;
	var query = "?killmockingbird=" + DISABLE_TWITTER
	          + "&effect=" + this.id.substr(7)
	          + "&scroll_text=" + $('scroll_text').value
	          ;

	new AjaxRequest( target+query, function(request) {
		$('cgi_output').innerHTML = request.responseText;
		
		/* Give the Fonera some time to realize, that
		 * the temporary file has been touched
		 */
		window.setTimeout( 'show_old_text();', 100 );
	}).poll();
}

function onload_handler()
{
	var all_buttons = document.getElementsByTagName('input');
	for( i = 0 ; i < all_buttons.length ; i++ ) {
		if (all_buttons[i].type == 'submit') {
			AddEvent( all_buttons[i], 'click', button_onclick_handler );
		}
	}
	show_old_text();	/* Display current display content in page */
}

document.addEventListener('DOMContentLoaded', onload_handler);

//EOF
