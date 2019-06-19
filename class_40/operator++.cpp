/*************************************************************************
 ******* File Name: operator++.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 19 Jun 2019 10:42:55 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
	int mValue;
public:
	Test(int i)
	{
		mValue = i;
	}

	int value()
	{
		return mValue;
	}

	Test& operator ++ ()
	{
		mValue++;

		return *this;
	}

	Test operator ++ (int)
	{
		Test ret(mValue);

		mValue++;

		return ret;
	}
};

int main(int argc, char** argv)
{
	Test t(0);

	Test t1 = ++t;

	cout << t1.value() << endl;
	cout << t.value() << endl;

	Test t2 = t++;

	cout << t2.value() << endl;
	cout << t.value() << endl;

    return 0;
}
