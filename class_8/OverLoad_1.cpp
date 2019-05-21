/*************************************************************************
 ******* File Name: OverLoad.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 21 May 2019 09:51:11 PM CST
 ************************************************************************/

#include <iostream>
#include <string.h>

using namespace std;

//#define test_overload
#define test_func_addr

#ifdef test_overload

int func(int x)
{
	return x;
}

int func(int a, int b)
{
	return a+b;
}

int func(const char* s)
{
	return strlen(s);
}

int main(int argc, char ** argv)
{
	cout << "func(3) = " << func(3) << endl;
	cout << "func(4,5) = " << func(4, 5) << endl;
	cout << "func(\"oh, f**k\") = " << func("oh, f**k") << endl;

	return 0;
}

/*
 * result:
 * func(3) = 3
 * func(4,5) = 9
 * func("oh, f**k") = 8
 */

#endif

#ifdef test_func_addr 

int add(int a, int b)
{
	return a+b;
}

int add(int a, int b, int c)
{
	return a+b+c;
}

int main(int argc, char** argv)
{
	cout << "(int(*)(int, int))add = " << (unsigned long)((int(*)(int, int))add) << endl;
	cout << "(int(*)(int, int, int))add = " << (unsigned long)((int(*)(int, int, int))add) << endl;

	return 0;
}

/*
 * result:
 * (int(*)(int, int))add = 4196502
 * (int(*)(int, int, int))add = 4196522
 */

#endif
