/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 04 Jul 2019 10:07:55 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class BaseA
{
	int ma;
public:
	BaseA(int a)
	{
		ma = a;
	}

	int getA()
	{
		return ma;
	}
};

class BaseB
{
	int mb;
public:
	BaseB(int b)
	{
		mb = b;
	}

	int getB()
	{
		return mb;
	}
};

class Derived : public BaseA, public BaseB
{
	int mc;
public:
	Derived(int a, int b, int c) : BaseA(a), BaseB(b)
	{
		mc = c;
	}

	int getC()
	{
		return mc;
	}

	unsigned long getCaddr()
	{
		return (unsigned long)(&mc);
	}

	void print()
	{
		cout << "ma = " << getA() << ", "
			 << "mb = " << getB() << ", "
			 << "mc = " << mc << endl;
	}
};

int main(int argc, const char* argv[])
{
	cout << "sizeof(Derived) = " << sizeof(Derived) << endl;

	Derived d(1, 2, 3);

	d.print();

	cout << endl;

	BaseA* pa = &d;
	BaseB* pb = &d;

	cout << "pa->getA() = " << pa->getA() << endl;
	cout << "pb->getB() = " << pb->getB() << endl;
	cout << "d.getC() = " << d.getC() << endl;

	cout << endl;

	void* paa = pa;
	void* pbb = pb;

	if(paa == pbb)
	{
		cout << "This is same addr" << endl;
	}
	else
	{
		cout << "Error: diff addr" << endl;
	}

	cout << endl;

	cout << "pa = " << pa << endl;
	cout << "pb = " << pb << endl;
	cout << "d = " << &d << endl;
	cout << "&d.mc = " << hex << d.getCaddr() << endl;

    return 0;
}

/*
 * result:
 * sizeof(Derived) = 12
 * ma = 1, mb = 2, mc = 3
 *
 * pa->getA() = 1
 * pb->getB() = 2
 * d.getC() = 3
 *
 * Error: diff addr
 *
 * pa = 0x7ffd8fbff020
 * pb = 0x7ffd8fbff024
 * d = 0x7ffcd562d280
 * &d.mc = 7ffd8fbff028
 */
