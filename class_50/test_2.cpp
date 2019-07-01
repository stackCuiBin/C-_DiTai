/*************************************************************************
 ******* File Name: test_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 01 Jul 2019 10:01:06 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Demo
{
	int mi;
	int mj;
public:
	Demo(int i, int j)
	{
		mi = i;
		mj = j;
	}

	int getmi()
	{
		return mi;
	}

	int getmj()
	{
		return mj;
	}

	int add(int value)
	{
		return mi + mj + value;
	}
};

int main(int argc, const char* argv[])
{
	Demo d(1, 2);

	cout << "d.mi = " << d.getmi() << endl;
	cout << "d.mj = " << d.getmj() << endl;
	cout << "add(3) = " << d.add(3) << endl;

    return 0;
}
