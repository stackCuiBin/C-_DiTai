/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 21 Jul 2019 03:26:03 PM CST
 ************************************************************************/

#include <iostream>
#include <exception>
#include <cstdlib>

using namespace std;

void my_unexpected()
{
	cout << "void my_unexcepted()" << endl;

	//exit(1);
	throw 1;
}

void func() throw(int)
{
	cout << "void func()" << endl;

	throw 'c';
}


int main(int argc, const char* argv[])
{
	set_unexpected(my_unexpected);

	try
	{
		func();
	}
	catch(int)
	{
		cout << "catch(int)" << endl;
	}
	catch(char)
	{
		cout << "catch(char)" << endl;
	}

    return 0;
}

/*
 * result
 *
 * 1, my_unexpected()中调用exit(1);
 * void func()
 * void my_unexcepted()
 *
 * 2, my_unexpected()中调用throw 1；
 * void func()
 * void my_unexcepted()
 * catch(int)
 */
