
#include <stdlib.h>
#include <stdio.h>

#include "ngr2ll.h"

int nerrors = 0;

void check_en(char *ngr, long expected_east, long expected_north)
{
	long east, north;
	_ngr2en(ngr, &east, &north);
	if (east != expected_east) {
		printf("ERROR: %s gives easting of %ld instead of %ld\n", ngr, east, expected_east);
		nerrors++;
	}
	if (north != expected_north) {
		printf("ERROR: %s gives northing of %ld instead of %ld\n", ngr, north, expected_north);
		nerrors++;
	}
}

void main()
{
	double lat, lon;

	if (ngr2ll("ZZ123456", &lat, &lon) != 1) {
		printf("Did NOT handle invalid ngr\n");
		nerrors++;
	}

	// Check the NGR to easting/northings sub function
	check_en("TG5140913177", 651409, 313177);
	check_en("TG", 650000, 350000);
	check_en("TG123123", 612350, 312350);

	ngr2ll("TG5140913177",&lat,&lon);
	if (abs(lat - 52.657555) > .0001) {
		printf("ERROR: Latitude for TG5140913177 is reported as %f: Expected 52.657555\n", lat);
		nerrors++;
	}
	if (abs(lon - 1.717907) > .0001) {
		printf("ERROR: Longitude for TG5140913177 is reported as %f: Expected 1.717907\n", lon);
		nerrors++;
	}

	if (nerrors) {
		printf("Found %d errors\n", nerrors);
	} else {
		printf("All tests completed successfully\n");
	}

	exit(0);
}


