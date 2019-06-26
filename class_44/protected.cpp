/*************************************************************************
 ******* File Name: protected.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 26 Jun 2019 10:26:12 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Parent
{
protected:
	int mv;
public:
	Parent()
	{
		mv = 100;
	}

	int value()
	{
		return mv;
	}
};

class Child : public Parent
{
public:
	void addValue(int v)
	{
		mv = mv + v;
	}
};

int main(int argc, char** argv)
{
	Parent p;

	cout << "p.mv = " << p.value() << endl;

	//p.mv = 110;	// error
	
	Child c;

	cout << "c.mv = " << c.value() << endl;

	c.addValue(20);

	cout << "c.mv = " << c.value() << endl;

	//c.mv = 150;	// error

    return 0;
}
