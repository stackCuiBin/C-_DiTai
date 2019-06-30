/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 30 Jun 2019 10:36:04 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Parent
{
public:
	int mi;

	int add(int i)
	{
		mi += i;
	}

	int add(int a, int b)
	{
		mi += (a + b);
	}

	void print()
	{
		cout << "I'm Parent." << endl;
	}
};

class Child : public Parent
{
public:
	int mv;

	int add(int x, int y, int z)
	{
		mv += (x + y + z);
	}

	void print()
	{
		cout << "I'm Child." << endl;
	}
};

/* 在编译这个函数的时候，编译器不可能知道指针p究竟指向了什么。但是编译器没有
 * 理由报错。于是，编译器认为最安全的做法是调用父类print()函数，因为父类和子类
 * 肯定有相同的print函数*/
void how_to_print(Parent* p)
{
	p->print();
}

int main(int argc, const char* argv[])
{
	Parent p;
	Child c;

	p = c;

	Parent p1(c);

	Parent& rp = c;
	Parent* pp = &c;

	rp.mi = 100;
	rp.add(5);			// 没有发生同名覆盖
	rp.add(10, 10);		// 没有发生同名覆盖

	/* 编译不过，子类退化为父类，只能访问父类成员 */
	//pp->mv = 1000;
	//pp->add(1, 2, 3);


	/*
	 * 问题分析
	 * 	编译期间，编译器只能根据指针类型判断所指向的对象
	 * 	根据赋值兼容，编译器认为父类指针指向的是父类对象
	 * 	因此，编译结果只能是调用父类中定义的同名函数
	 */
	how_to_print(&p);	// I'm Parent
	how_to_print(&c);	// I'm Parent

    return 0;
}
