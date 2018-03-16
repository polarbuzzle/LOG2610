/*
 * baz.c
 *
 *  Created on: 2013-08-15
 *      Author: Francis Giraldeau <francis.giraldeau@gmail.com>
 */

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "whoami.h"

int main(int argc, char **argv) {

	int n = atoi(argv[1]);
	int ctr = atoi(argv[2]);

	if (ctr == n) {
		exit(0);
	}

	ctr++;

	char* argument;;	
	asprintf(&argument, "%d", ctr);
	increment_rank();
	whoami("baz");
	execlp("foo", "foo", argv[1], argument, NULL);
	return 0;
}
