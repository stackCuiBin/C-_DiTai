/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Fri 05 Jul 2019 10:37:02 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}

	virtual void func()
	{
		cout << "Base::func()" << endl;
	}

	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived()" << endl;
	}

	virtual void func()
	{
		cout << "Derived::func()" << endl;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}
};

int main(int argc, const char* argv[])
{
	Base* p = new Derived;

	delete p;

    return 0;
}

/*
 * result:
 *
 * (1) ~Base() 不是虚函数
 * Base()
 * Derived()
 * ~Base()
 *
 * (2) ~Base() 是虚函数
 * Base()
 * Derived()
 * ~Derived()
 * ~Base()
 *
 */
