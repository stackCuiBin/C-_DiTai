/*************************************************************************
 ******* File Name: main.c
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 01 Jul 2019 10:19:55 PM CST
 ************************************************************************/

#include <stdio.h>
#include "demo.h"

int main(int argc, char* argv[])
{
	Demo* d = Demo_Create(1, 2);

	printf("d.mi  = %d \n", getmI(d));
	printf("d.mj  = %d \n", getmJ(d));
	printf("add(3) = %d \n", add(d, 3));

	// error
	//d->mi = 100;
	
	Demo_Free(d);

    return 0;
}
