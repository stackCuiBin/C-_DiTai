/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 01 Jul 2019 09:28:50 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class A
{
	int i;
	int j;
	char c;
	double d;
public:
	void print()
	{
		cout << "i = " << i << ", "
			 << "j = " << j << ", "
			 << "c = " << c << ", "
			 << "d = " << d << endl;
	}
};

struct B
{
	int i;
	int j;
	char c;
	double d;
};

struct C
{
	int i;
	double d;
};

int main(int argc, const char* argv[])
{
	A a;
	
	cout << "sizeof(int) = " << sizeof(int) << endl;
	cout << "sizeof(char) = " << sizeof(char) << endl;
	cout << "sizeof(double) = " << sizeof(double) << endl;
	/* double 8字节整数倍地址对齐 */
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(a) = " << sizeof(a) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;

	a.print();

	B* b = reinterpret_cast<B*>(&a);
	b->i = 1;
	b->j = 2;
	b->c = 'c';
	b->d = 3;

	a.print();

    return 0;
}
