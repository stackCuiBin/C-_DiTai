/*************************************************************************
 ******* File Name: test_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Fri 05 Jul 2019 11:24:35 PM CST
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

	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{

};

int main(int argc, const char* argv[])
{
	/* 1 test */
	Base* p = new Derived;

	Derived* pd = dynamic_cast<Derived*>(p);

	cout << "pd = " << pd << endl;
	/* 1 test end */

	/* 2 test */
	Base* pp = new Base;

	/* 使用父类指针初始化子类指针，转换不成功 */
	Derived* ppd = dynamic_cast<Derived*>(pp);

	if(ppd != NULL)
	{
		cout << "ppd = " << ppd << endl;
	}
	else
	{
		cout << "cast error" << endl;
	}
	/* 2 test end */

	delete p;

	delete pp;

    return 0;
}

/*
 * result:
 * 
 * 1 test
 * Base()
 * pd = 0x245bc20
 *
 * 2 test
 * Base()
 * cast error
 *
 * ~Base()
 * ~Base()
 */
