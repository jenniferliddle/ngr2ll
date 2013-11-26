ngr2ll
======

C code to convert from National Grid Reference to Latitude and Longitude

This code is a conversion into C of the javascript written by Chris Veness

Ordnance Survey Grid Reference functions  (c) Chris Veness 2005-2012
 - www.movable-type.co.uk/scripts/gridref.js
 - www.movable-type.co.uk/scripts/latlon-gridref.html

Converted from the original Javascript into C by Jennifer Liddle <jennifer@jsquared.co.uk>
 - https://github.com/jenniferliddle/ngr2ll

You are welcome to re-use these scripts under a creative commons license,
http://creativecommons.org/licenses/by/3.0/ without any warranty express or implied,
provided solely that you retain this copyright notice and links.


USAGE
=====

#include "ngr2ll.h"

double lat, long;

ngr2ll("TG5140913177",&lat,&lon);


