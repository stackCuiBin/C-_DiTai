/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 16 Jul 2019 10:56:49 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

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
char IsPtr(T* v)
{
	return 't';
}

int IsPtr(...)
{
	return 0;
}

#define ISPTR(p) (sizeof(IsPtr(p)) == sizeof(char))

int main(int argc, const char* argv[])
{
	int i = 0;
	int* p = &i;

	cout << "p is a pointer: " << ISPTR(p) << endl;
	cout << "i is a pointer: " << ISPTR(i) << endl;
	
	Test t;
	Test* pt = &t;

	cout << "t is a pointer: " << ISPTR(t) << endl;
	cout << "pt is a pointer: " << ISPTR(pt) << endl;

    return 0;
}

/*
 * result:
 * p is a pointer: 1
 * i is a pointer: 0
 * t is a pointer: 0
 * pt is a pointer: 1
 */
