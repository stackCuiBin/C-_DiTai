/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 04 Jul 2019 11:03:07 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class BaseA
{
public:
	virtual void funcA()
	{
		cout << "BaseA::funcA()" << endl;
	}
};

class BaseB
{
public:
	virtual void funcB()
	{
		cout << "BaseB::funcB()" << endl;
	}
};

class Derived : public BaseA, public BaseB
{

};

int main(int argc, const char* argv[])
{
	Derived d;
	BaseA* pa = &d;
	BaseB* pb = &d;

	cout << "sizeof(d) = " << sizeof(d) << endl;
	cout << endl;

	cout << "Using pa to call funcA() ..." << endl;
	pa->funcA();
	cout << "pa = " << pa  << endl;
	cout << endl;

	cout << "Using pb to call funcB() ..." << endl;
	pb->funcB();
	cout << "pb = " << pb << endl;
	cout << endl;

	BaseB* pbb = (BaseB*)pa;
	cout << "Using pbb to call funcB() ..." << endl;
	pbb->funcB();
	cout << "pbb = " << pbb << endl;
	cout << endl;

	pbb = dynamic_cast<BaseB*>(pa);
	cout << "Using new pbb to call funcB() ..." << endl;
	pbb->funcB();
	cout << "pbb = " << pbb << endl;

    return 0;
}

/*
 * result:
 * sizeof(d) = 16
 *
 * Using pa to call funcA() ...
 * BaseA::funcA()
 * pa = 0x7ffdf3798f00
 *
 * Using pb to call funcB() ...
 * BaseB::funcB()
 * pb = 0x7ffdf3798f08
 *
 * Using pbb to call funcB() ...
 * BaseA::funcA()
 * pbb = 0x7ffdf3798f00
 *
 * Using new pbb to call funcB() ...
 * BaseB::funcB()
 * pbb = 0x7ffdf3798f08
 */
