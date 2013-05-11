/*
 * myfunctions.c
 *
 *  Created on: 10/mag/2013
 *      Author: Toni Cafiero
 */
#include <string.h>
#include <myfunctions.h>

void mycopy(char *p, const char *string, int n)
{
	strncpy(p, string, n);
}
