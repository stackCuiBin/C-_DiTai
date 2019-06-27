/*************************************************************************
 ******* File Name: conflict.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 27 Jun 2019 10:49:21 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Parent
{
public:
	int mi;

	Parent()
	{
		cout << "Parent : " << "&mi = " << &mi << endl;
	}
};

class Child : public Parent
{
public:
	int mi;

	Child()
	{
		cout << "Child : " << "&mi = " << &mi << endl;
	}
};

int main(int argc, const char* argv[])
{
	Child c;

	c.mi = 100;

	c.Parent::mi = 1000;

	cout << "&c.mi = " << &c.mi << endl;
	cout << "c.mi = " << c.mi << endl;

	cout << "&c.Parent::mi = " << &c.Parent::mi << endl;
	cout << "c.Parent::mi = " << c.Parent::mi << endl;

    return 0;
}

/*
 * result:
 * Parent : &mi = 0x7ffe314ac8c0
 * Child : &mi = 0x7ffe314ac8c4
 * &c.mi = 0x7ffe314ac8c4
 * c.mi = 100
 * &c.Parent::mi = 0x7ffe314ac8c0
 * c.Parent::mi = 1000
 */
