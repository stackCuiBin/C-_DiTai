/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 19 May 2019 04:39:06 PM CST
 ************************************************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

//#define test_bool
#define test_bool_int

#ifdef test_bool 
int main(int argc, char* argv[])
{
	bool b = 0;
	printf("b = %d\n", b);

	b++;
	printf("b = %d\n", b);

	b = b - 3;
	printf("b = %d\n", b);

	return 0;
}

/*
 * result:
 * b = 0
 * b = 1
 * b = 1
 */

#endif

#ifdef test_bool_int
int main(int argc, char* argv[])
{
	bool b = false;
	int a = b;
	printf("sizeof(b) = %d\n", (int)sizeof(b));
	printf("b = %d, a = %d\n", b, a);

	b = 3;
	a = b;
	printf("b = %d, a = %d\n", b, a);

	b = -5;
	a = b;
	printf("b = %d, a = %d\n", b, a);

	a = 10;
	b = a;
	printf("a = %d, b = %d\n", a, b);

	a = 0;
	b = a;
	printf("a = %d, b = %d\n", a, b);

	return 0;
}

/*
 * result:
 * sizeof(b) = 1
 * b = 0, a = 0
 * b = 1, a = 1
 * b = 1, a = 1
 * a = 10, b = 1
 * a = 0, b = 0
 */

#endif
