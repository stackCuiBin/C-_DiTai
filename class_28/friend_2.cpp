/*************************************************************************
 ******* File Name: friend_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sat 08 Jun 2019 10:38:03 AM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class ClassC
{
	const char* n;
public:
	ClassC(const char* n)
	{
		this->n = n;
	}

	friend class ClassB;
};

class ClassB
{
	const char* n;
public:
	ClassB(const char* n)
	{
		this->n = n;
	}

	void getClassCname(ClassC& c)
	{
		cout << "c.n = " << c.n << endl;
	}

	friend class ClassA;
};

class ClassA
{
	const char* n;
public:
	ClassA(const char* n)
	{
		this->n = n;
	}

	void getClassBname(ClassB& b)
	{
		cout << "b.n = " << b.n << endl;
	}
};

int main(int argc, char** argv)
{
	ClassA A("A");
	ClassB B("B");
	ClassC C("C");

	A.getClassBname(B);
	B.getClassCname(C);

    return 0;
}
