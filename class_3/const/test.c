/*************************************************************************
 ******* File Name: test.c
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sat 18 May 2019 08:53:16 PM CST
 ************************************************************************/

#include <stdio.h>

//#define test_const
#define test_const_define

#ifdef test_const

int main()
{
	const int c = 0;
	int *p = (int *)&c;

	printf("Begin...\n");

	*p = 5;
	printf("c = %d\n", c);
	printf("*p = %d\n", *p);

	printf("End...\n");

	return 0;
}

/*
 * result:
 * c = 5
 * *p = 5
 */

#endif

#ifdef test_const_define

void f() 
{
	#define a 3
	const int b = 4;
}

void g()
{
	printf("a = %d\n", a);
	//printf("b = %d\n", b);
}

int main()
{
	const int A = 1;
	const int B = 2;
	int array[A + B] = {0};	// compile error: A and B are variables and cannot determine the length of the array
	int i = 0;

	for(i=0; i<(A+B); i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}

	f();
	g();

	return 0;
}

#endif
