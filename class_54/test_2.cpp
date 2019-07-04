/*************************************************************************
 ******* File Name: test_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 04 Jul 2019 11:34:37 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Base
{
protected:
	int mi;
public:
	Base(int i)
	{
		mi = i;
	}

	int getMi()
	{
		return mi;
	}

	bool equal(Base* obj)
	{
		return (this == obj);
	}
};

class Interface1
{
public:
	virtual void add(int i) = 0;
	virtual void minus(int i) = 0;
};

class Interface2
{
	virtual void multiply(int i) = 0;
	virtual void divide(int i) = 0;
};

class Derived : public Base, public Interface1, public Interface2
{
public:
	Derived(int i) : Base(i)
	{}

	void add(int i)
	{
		mi += i;
	}

	void minus(int i)
	{
		mi -= i;
	}

	void divide(int i)
	{
		if(i != 0)
		{
			mi /= i;
		}
	}

	void multiply(int i)
	{
		mi *= i;
	}
};

int main(int argc, const char* argv[])
{
	Derived d(100);

	cout << "d.mi = " << d.getMi() << endl;
	cout << endl;

	d.add(10);
	d.divide(11);
	d.minus(5);
	d.multiply(8);
	cout << "d.mi = " << d.getMi() << endl;

	Derived* pd = &d;
	Interface1* p1 = &d;
	Interface2* p2 = &d;
	cout << "p1 == pd : " << pd->equal(dynamic_cast<Base*>(p1)) << endl;
	cout << "p2 == pd : " << pd->equal(dynamic_cast<Base*>(p2)) << endl; 
    return 0;
}

/*
 * result:
 * d.mi = 100
 *
 * d.mi = 40
 * p1 == pd : 1
 * p2 == pd : 1
 */
