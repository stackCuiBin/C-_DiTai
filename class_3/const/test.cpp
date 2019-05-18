/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sat 18 May 2019 08:59:46 PM CST
 ************************************************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

//#define test_const
#define test_const_define

#ifdef test_const

int main()
{
	const int c = 0;
	int* p = (int *)&c;

	printf("Begin...\n");

	*p = 5;
	printf("c = %d\n", c);
	printf("*p = %d\n", *p);

	printf("End...\n");

	return 0;
}

/*
 * result:
 * c = 0
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
	printf("a = %d\n", a);	// conpile ok: the processing of a is in the preprocessing stage, this statement is equal to 'printf("a = %d\n", 3);'
	printf("b = %d\n", b);	// compile error: the scope of variable b is in the f function, and cannot be accessed in the g function.
}

int main()
{
	const int A = 1;
	const int B = 2;
	int array[A + B] = {0};	// compile ok
	
	for(int i=0; i<(A+B); i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}

	f();
	g();

	return 0;
}

#endif

