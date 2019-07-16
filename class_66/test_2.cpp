/*************************************************************************
 ******* File Name: test_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 16 Jul 2019 10:38:07 PM CST
 ************************************************************************/

#include <iostream>
#include <typeinfo>

using namespace std;

class Base
{
public:
	virtual ~Base()
	{}
};

class Derived : public Base
{
public:

};

void test(Base* p)
{
	const type_info& tb = typeid(*p);

	cout << tb.name() << endl;
}

int main(int argc, const char* argv[])
{
	int i = 0;

	const type_info& tiv = typeid(i);
	const type_info& tii = typeid(int);

	cout << (tii == tiv) << endl;

	Base b;
	Derived d;

	test(&b);
	test(&d);

    return 0;
}

/*
 * result:
 *
 * 没有虚函数时：
 * 1
 * 4Base
 * 4Base
 *
 * 有虚函数时：
 * 1
 * 4Base
 * 7Derived
 */
