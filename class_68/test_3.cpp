/*************************************************************************
 ******* File Name: test_3.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 17 Jul 2019 11:31:02 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

int func(int i, int j) throw(int, char)
{
	if((0 < j) && (j < 10))
	{
		return (i+j);
	}
	else
	{
		//throw 0;
		throw '0';
	}
}

void test(int i) try
{
	cout << "func(i, i) = " << func(i, i) << endl;
}
catch(int exc)
{
	cout << "Exception: " << exc << endl;
}
catch(...)
{
	cout << "Exception..." << endl;
}

int main(int argc, const char* argv[])
{
	test(5);
	test(10);

    return 0;
}
