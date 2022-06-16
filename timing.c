//
//  timing.c
//  
//
//  Created by Jianwei Liao on 6/25/12.
//  Copyright (c) 2012 Southwest University. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "timing.h"

int main(int argc, char *argv[])
{
	struct timeval start;
	/* get the start point */	
	start = time_start();
   
	/* Doing sth here, I select to sleep two seconds... */
	sleep(2);

	/* print out the consumed time in ms */
	printf("Comsumed Time:%ld ms\n",msdiff(start));
	return EXIT_SUCCESS;
}
