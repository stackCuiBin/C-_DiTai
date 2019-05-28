/*************************************************************************
 ******* File Name: InitializationList.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 28 May 2019 11:08:13 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Value
{
private:
	//int mi = 1;	// warnning: should compile with -std=c++11 or -std=gnu++11
	int mi;
public:
	Value(int i)
	{
		cout << "i = " << i << endl;
		mi = i;
	}
	int getMI()
	{
		return mi;
	}
};

class Test
{
private:
	const int ci;
	Value m2;
	Value m3;
	Value m1;
public:
	Test() : m1(1),m2(2),m3(3),ci(100)
	{
		cout << "Test::Test()" << endl;
	}
	int getCI()
	{
		return ci;
	}
	void setCI(int v)
	{
		int* p = const_cast<int*>(&ci);

		*p = v;
	}
};

int main(int argc, char** argv)
{
	Test t;

	cout << "t.ci = " << t.getCI() << endl;

	t.setCI(10);

	cout << "t.ci = " << t.getCI() << endl;

    return 0;
}

/*
 * result:
 * i = 2
 * i = 3
 * i = 1
 * Test::Test()
 * t.ci = 100
 * t.ci = 10
 */
