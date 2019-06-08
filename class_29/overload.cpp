/*************************************************************************
 ******* File Name: overload.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sat 08 Jun 2019 11:07:59 AM CST
 ************************************************************************/

#include <iostream>

using namespace std;

void func()
{
	cout << "void func()" << endl;
}

void func(int i)
{
	cout << "void func(int i), i = " << i << endl;
}

class Test
{
	int i;

public:

	Test()
	{
		cout << "Test::Test()" << endl;
		this->i = 0;
	}

	Test(int i)
	{
		cout << "Test::Test(int i)" << endl;
		this->i = i;
	}

	Test(Test& obj)
	{
		cout << "Test::Test(Test& obj)" << endl;
		this->i =  obj.i;
	}

	static void func()
	{
		cout << "void Test::func()" << endl;
	}

	void func(int i)
	{
		cout << "void Test::func(int i), i =" << i <<  endl;
	}

	int getI()
	{
		return i;
	}
};

int main(int argc, char** argv)
{
	Test t;
	Test t1(1);
	Test t2(t1);

	func();
	Test::func();

	func(2);
	t1.func(2);
	t1.func();

    return 0;
}

/*
 * result:
 * Test::Test()
 * Test::Test(int i)
 * Test::Test(Test& obj)
 * void func()
 * void Test::func()
 * void func(int i), i = 2
 * void Test::func(int i), i =2
 * void Test::func()
 */
