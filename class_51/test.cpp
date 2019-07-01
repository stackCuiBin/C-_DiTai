/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 01 Jul 2019 10:36:37 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Demo
{
protected:
	int mi;
	int mj;
public:
	virtual void print()
	{
		cout << "mi = " << mi << ", "
			 << "mj = " << mj << endl;
	}
};

class Derived : public Demo
{
	int mk;
public:
	Derived(int i, int j, int k)
	{
		mi = i;
		mj = j;
		mk = k;
	}

	void print()
	{
		cout << "mi = " << mi << ", "
			 << "mj = " << mj << ", "
			 << "mk = " << mk << endl;
	}
};

struct Test
{
	void* p;
	int mi;
	int mj;
	int mk;
};

int main(int argc, const char* argv[])
{
	Derived d(1, 2, 3);
	
	/* 虚函数表地址占8个字节，而且在数据结构前段 */
	cout << "sizeof(Demo) = " << sizeof(Demo) << endl;
	cout << "sizeof(Derived) = " << sizeof(Derived) << endl;
	cout << "sizeof(Test) = " << sizeof(Test) << endl;

	d.print();

	Test* t = reinterpret_cast<Test*>(&d);
	t->mi = 10;
	t->mj = 20;
	t->mk = 30;

	d.print();

    return 0;
}

/*
 * result:
 * sizeof(Demo) = 16
 * sizeof(Derived) = 24
 * sizeof(Test) = 24
 * mi = 1, mj = 2, mk = 3
 * mi = 10, mj = 20, mk = 30
 */
