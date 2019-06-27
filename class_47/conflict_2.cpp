/*************************************************************************
 ******* File Name: conflict_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 27 Jun 2019 11:01:26 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Parent
{
public:
	int mi;

	void add(int v)
	{
		mi += v;
	}

	void add(int a, int b)
	{
		mi += (a + b);
	}
};

class Child : public Parent
{
public:
	int mi;

	/* 这个add因为和父类中的add不在一个作用域中，所以没有发生重载，将会隐藏覆盖
	 * 父类中的add。调用c.add(int)也会报错，因为被隐藏了。*/
	void add(int x, int y, int z)
	{
		mi += (x + y + z);
	}
};

int main(int argc, const char* argv[])
{
	Child c;

	c.mi = 100;
	c.Parent::mi = 200;

	cout << "c.mi = " << c.mi << endl;
	cout << "c.Parent::mi = " << c.Parent::mi << endl;

	//c.add(1);	// Parent::mi
	//c.add(2, 3);	// Parent::mi
	c.Parent::add(1);
	c.Parent::add(2, 3);
	c.add(4, 5, 6);

	cout << "c.mi = " << c.mi << endl;
	cout << "c.Parent::mi = " << c.Parent::mi << endl;

    return 0;
}

/*
 * result:
 * c.mi = 100
 * c.Parent::mi = 200
 * c.mi = 115
 * c.Parent::mi = 206
 */
