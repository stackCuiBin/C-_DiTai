/*************************************************************************
 ******* File Name: test_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 08 Jul 2019 11:14:11 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

template < typename T>
T Max(T a, T b)
{
	cout << "T Max(T a, T b)" << endl;

	return a > b ? a : b; 
}

int Max(int a, int b)
{
	cout << "int Max(int a, int b)" << endl;

	return a > b ? a : b;
}

template <typename T>
T Max(T a, T b, T c)
{
	cout << "T Max(T a, T b, T c)" << endl;

	return Max(Max(a, b), c);
}

int main(int argc, const char* argv[])
{
	int a = 10;
	int b = 11;

	Max(a, b);				// 普通函数 Max(int, int)
	cout << endl;
	Max<>(a, b);			// 模板函数 Max(int, int)
	cout << endl;
	Max(0.1, 0.2);			// 模板函数	Max(double, double)
	cout << endl;
	Max(0.3, 0.4,0.4);		// 模板函数 Max(double, double, double)
	cout << endl;
	Max('a', 100);			// 普通函数 Max(int, int)
	cout << endl;
	Max(1, 2, 3);

    return 0;
}

/*
 * result:
 * int Max(int a, int b)
 *
 * T Max(T a, T b)
 *
 * T Max(T a, T b)
 *
 * T Max(T a, T b, T c)
 * T Max(T a, T b)
 * T Max(T a, T b)
 *
 * int Max(int a, int b)
 *
 * T Max(T a, T b, T c)
 * int Max(int a, int b)
 * int Max(int a, int b)
 *
 */
