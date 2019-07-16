/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 16 Jul 2019 10:56:49 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

/*
void test(int i)
{
	cout << "void test(int i)" << endl;
}

template
< typename T >
void test(T v)
{
	cout << "void test(T v)" << endl;
}

void test(...)
{
	cout << "void test(...)" << endl;
}
*/

class Test
{
public:
	Test()
	{
	}

	virtual ~Test()
	{
	}
};

template
< typename T >
bool IsPtr(T* v)
{
	return true;
}

bool IsPtr(...)
{
	return false;
}

int main(int argc, const char* argv[])
{
	int i = 0;
	int* p = &i;

	cout << "p is a pointer: " << IsPtr(p) << endl;
	cout << "i is a pointer: " << IsPtr(i) << endl;
	
	Test t;
	Test* pt = &t;

	cout << "t is a pointer: " << IsPtr(t) << endl;
	cout << "pt is a pointer: " << IsPtr(pt) << endl;

    return 0;
}

/*
 * result:
 * 可能环境不一样，输出结果也不太一样
 * p is a pointer: 1
 * i is a pointer: 0
 * t is a pointer: 0
 * pt is a pointer: 1
 */
