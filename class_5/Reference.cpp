/*************************************************************************
 ******* File Name: Reference.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 19 May 2019 10:06:35 PM CST
 ************************************************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

//#define test_1
//#define test_2
#define func_return_refernce

#ifdef test_1
struct TRef
{
	char& r;
};

int main(int argc, char** argv)
{
	char c = 'c';
	char& rc = c;
	TRef ref = { c };

	printf("sizeof(char&) = %d\n", (int)sizeof(char&));
	printf("sizeof(rc) = %d\n", (int)sizeof(rc));
	printf("sizeof(TRef) = %d\n", (int)sizeof(TRef));
	printf("sizeof(ref.r) = %d\n", (int)sizeof(ref.r));

	return 0;
}

/*
 * result:
 * sizeof(char&) = 1
 * sizeof(rc) = 1
 * sizeof(TRef) = 8
 * sizeof(ref.r) = 1
 */

#endif

#ifdef test_2

struct TRef
{
	char* before;
	char& ref;
	char* after;
};

int main(int argc, char** argv)
{
	char a = 'a';
	char& b = a;
	char c = 'c';

	TRef r = {&a, b, &c};

	cout << "sizeof(r) = " << sizeof(r) << endl;
	cout << "sizeof(r.before) = " << sizeof(r.before) << endl;
	cout << "sizeof(r.after) = " << sizeof(r.after) << endl;
	cout << "&r.before = " << &r.before << endl;
	cout << "&r.after = " << &r.after << endl;

	return 0;
}

/*
 * result:
 * sizeof(r) = 24
 * sizeof(r.before) = 8
 * sizeof(r.after) = 8
 * &r.before = 0x7ffccf7ed370
 * &r.after = 0x7ffccf7ed380
 */

#endif 

#ifdef func_return_refernce 

int& demo()		// int* const
{
	int d = 0;

	cout << "demo: d = " << d <<endl;

	return d;	//return &d;
}

int& func()
{
	static int s = 0;

	cout << "func: s = " << s << endl;

	return s;
}

int main(int argc, char** argv)
{
	int& rd = demo();
	int& rs = func();

	cout << endl;
	cout << "main: rd = " << rd << endl;
	cout << "main: rs = " << rs << endl;
	cout << endl;

	rd = 10;
	rs = 11;

	demo();
	func();

	cout << endl;
	cout << "main: rd = " << rd << endl;
	cout << "main: rs = " << rs << endl;
	cout << endl;

	return 0;
}

/*
 * result:
 * demo: d = 0
 * func: s = 0
 *
 * main: rd = 12345678
 * main: rs = 0
 *
 * demo: d = 10
 * func: s = 11
 *
 * main: rd = 12345678
 * main: rs = 11
 */
 
// note: Do not return a reference to a local variable.

#endif 
