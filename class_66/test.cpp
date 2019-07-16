/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 16 Jul 2019 10:19:27 PM CST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
	virtual string type()
	{
		return "Base";
	}
};

class Derived : public Base
{
public:
	string type()
	{
		return "Derived";
	}

	void print()
	{
		cout << "I'm a Derived" << endl;
	}
};

class Child : public Base
{
public:
	string type()
	{
		return "Child";
	}
};

void test(Base* p)
{
	/* 危险的转换 */
	//Derived* d = static_cast<Derived*>(p);
	
	if(p->type() == "Derived")
	{
		Derived* d = static_cast<Derived*>(p);

		d->print();
	}

	//cout << dynamic_cast<Derived*>(p) << endl;
}

int main(int argc, const char* argv[])
{
	Base b;
	Derived d;
	Child c;

	test(&b);
	test(&d);
	test(&c);
    return 0;
}
