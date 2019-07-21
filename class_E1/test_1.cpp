/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 21 Jul 2019 11:35:49 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <exception>

using namespace std;

void my_terminate()
{
	cout << "void my_terminate() " << endl;

	//exit(1);
	abort();
}

class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
	}

	~Test()
	{
		cout << "~Test()" << endl;

		throw 2;
	}
};

int main(int argc, const char* argv[])
{
	set_terminate(my_terminate);

	static Test t;

	throw 1;

    return 0;
}

/*
 * result:
 *
 * 1, my_termiante()中调用exit(1);时
 * Test()
 * void my_terminate() 
 * ~Test()
 * Aborted (core dumped)
 *
 * 2，my_terminate()中调用abort();时
 * Test()
 * void my_terminate() 
 * Aborted (core dumped)
 *
 */
