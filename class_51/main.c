/*************************************************************************
 ******* File Name: main.c
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 01 Jul 2019 10:19:55 PM CST
 ************************************************************************/

#include <stdio.h>
#include "demo.h"

void run(Demo* pThis, int value)
{
	int ret = Demo_Add(pThis, 3);

	printf("ret = %d \n", ret);
}

int main(int argc, char* argv[])
{
	Demo* pb = Demo_Create(1, 2);
	Derived* pd = Derived_Create(1, 22, 333); 

	printf("pb->add(3) = %d \n", Demo_Add(pb, 3));
	printf("pd->add(3) = %d \n", Derived_Add(pd, 3));

	run(pb, 3);
	run(pd, 3);

	Demo_Free(pb);
	Demo_Free(pd);

    return 0;
}
