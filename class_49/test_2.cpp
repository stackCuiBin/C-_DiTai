/*************************************************************************
 ******* File Name: test_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 30 Jun 2019 11:40:14 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Parent
{
public:
	virtual void func()
	{
		cout << "Parent : func()" << endl;
	}

	virtual void func(int i)
	{
		cout << "Parent : func(int)" << endl;
	}

	virtual void func(int a, int b)
	{
		cout << "Parent : func(int, int)" << endl;
	}
};

class Child : public Parent
{
public:
	void func(int a, int b)
	{
		cout << "Child : func(int, int)" << endl;
	}

	void func(int x, int y, int z)
	{
		cout << "Child : func(int, int, int)" << endl;
	}
};

void run(Parent* p)
{
	p->func(1, 2);	// 展现多态的特性
					// 动态联编
}

int main(int argc, const char* argv[])
{
	Parent p;
	Child c;

	p.func();		// 静态联编
	p.func(1);		// 静态联编
	p.func(1, 2);	// 静态联编

	cout << endl;

	c.func(1, 2);	// 静态联编
	cout << endl;

	run(&p);
	run(&c);

    return 0;
}

/*
 * result:
 * Parent : func()
 * Parent : func(int)
 * Parent : func(int, int)
 *
 * Child : func(int, int)
 *
 * Parent : func(int, int)
 * Child : func(int, int)
 */
