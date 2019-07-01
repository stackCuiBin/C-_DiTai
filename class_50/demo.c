/*************************************************************************
 ******* File Name: Demo.c
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 01 Jul 2019 10:09:09 PM CST
 ************************************************************************/

#include "demo.h"
#include "malloc.h"

struct ClassDemo
{
	int mi;
	int mj;
};

Demo* Demo_Create(int i, int j)
{
	struct ClassDemo* ret = NULL;
	ret = (struct ClassDemo*)malloc(sizeof(struct ClassDemo));

	if(ret)
	{
		ret->mi = i;
		ret->mj = j;
	}

	return ret;
}

int getmI(Demo* pThis)
{
	struct ClassDemo* obj = (struct ClassDemo*)pThis;

	return obj->mi;
}

int getmJ(Demo* pThis)
{
	struct ClassDemo* obj = (struct ClassDemo*)pThis;

	return obj->mj;
}

int add(Demo* pThis, int value)
{
	struct ClassDemo* obj = (struct ClassDemo*)pThis;

	return obj->mi + obj->mj + value;
}

void Demo_Free(Demo* pThis)
{
	free(pThis);
}

