/*
 * main.c
 *
 *  Created on: 10/mag/2013
 *      Author: Toni Cafiero
 */
#include <stdio.h>
void __gcov_flush(void);

int main()
{
	printf("main enter\n");
	__gcov_flush();
	return 1;
}
