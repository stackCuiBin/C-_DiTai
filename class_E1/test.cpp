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

	exit(1);
	// abort();
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
	}
};

int main(int argc, const char* argv[])
{
	set_terminate(my_terminate);

	static Test t;
	//Test t;

	throw 1;

    return 0;
}

/*
 * result:
 *
 * 1, static Test t;
 * Test()
 * void my_terminate() 
 * ~Test()
 *
 * 2, Test t;
 * Test()
 * void my_terminate() 
 *
 */
