//
//  timing.h
//  
//
//  Created by Jianwei Liao on 6/25/14.
//  Copyright (c) 2014 Southwest University. All rights reserved.
//

#include <sys/time.h>
#define MILLION 1000000

/* should be called at the begining */
static struct timeval time_start(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv;
}

/* timediff in seconds */
static long sdiff(struct timeval start){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((MILLION*(tv.tv_sec-start.tv_sec)+tv.tv_usec-start.tv_usec)/1000000);
}

/* timediff in mili-seconds */
static long msdiff(struct timeval start){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((MILLION*(tv.tv_sec-start.tv_sec)+tv.tv_usec-start.tv_usec)/1000);
}

/* timediff in micro-seconds */
static long usdiff(struct timeval start){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((MILLION*(tv.tv_sec-start.tv_sec)+tv.tv_usec-start.tv_usec));
}


