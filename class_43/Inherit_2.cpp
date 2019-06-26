/*************************************************************************
 ******* File Name: Inherit_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 24 Jun 2019 11:13:05 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Parent
{
	int mv;
public:
	Parent()
	{
		mv = 100;
	}

	void method()
	{
		cout << "mv = " << mv << endl;
	}

	void set(int v)
	{
		mv = v;
	}

	int get()
	{
		cout << "mv = " << mv << endl;
		return mv;
	}
};

class Child : public Parent
{
public:
	void hello()
	{
		cout << "I'm child class" << endl;
	}

	void setMv(int v)
	{
		set(v);
		cout << "mv = " << get() << endl;
	}
};

int main(int argc, char** argv)
{
	Child c;

	c.hello();
	c.method();
	c.setMv(10);

	Parent p = c;

	p.method();

    return 0;
}

/*
 * result:
 * I'm child class
 * mv = 100
 * mv = 10
 * mv = 10
 * mv = 10
 */
