/*************************************************************************
 ******* File Name: this.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 04 Jun 2019 10:29:32 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
	int mi;
public:
	Test(int i);
	Test(const Test& t);
	int getMI();
	void print();
};

Test::Test(int i)
{
	mi = i;
}

Test::Test(const Test& t)
{
	mi = t.mi;
}

int Test::getMI()
{
	return mi;
}

void Test::print()
{
	cout << "this = " << this << endl;
}

int main(int argc, char** argv)
{
	Test t1(1);
	Test t2(2);
	Test t3(3);

	cout << "t1.mi = " << t1.getMI() << endl;
	cout << "&t1 = " << &t1 << endl;
	t1.print();

	cout << "t2.mi = " << t2.getMI() << endl;
	cout << "&t2 = " << &t2 << endl;
	t2.print();

	cout << "t3.mi = " << t3.getMI() << endl;
	cout << "&t3 = " << &t3 << endl;
	t3.print();

    return 0;
}

/*
 * result:
 * t1.mi = 1
 * &t1 = 0x7ffd6eca75d0
 * this = 0x7ffd6eca75d0
 * t2.mi = 2
 * &t2 = 0x7ffd6eca75e0
 * this = 0x7ffd6eca75e0
 * t3.mi = 3
 * &t3 = 0x7ffd6eca75f0
 * this = 0x7ffd6eca75f0
 */
