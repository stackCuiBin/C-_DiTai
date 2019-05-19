/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 19 May 2019 05:33:36 PM CST
 ************************************************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv)
{
	int a = 4;
	int& b = a;

	b = 5;

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);

	return 0;
}

/*
 * result:
 * a = 5
 * b = 5
 * &a = 0x7ffd7e5ccdec
 * &b = 0x7ffd7e5ccdec
 */
