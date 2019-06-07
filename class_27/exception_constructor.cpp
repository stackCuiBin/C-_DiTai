/*************************************************************************
 ******* File Name: exception_constructor.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Fri 07 Jun 2019 10:57:55 AM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
	int mi;
	int mj;
	bool mStatus;
public:
	Test(int i, int j):mStatus(false)
	{
		mi = i;

		return;

		mj = j;

		mStatus = true;
	}

	int getI()
	{
		return mi;
	}

	int getJ()
	{
		return mj;
	}

	bool status()
	{
		return mStatus;
	}
};

int main(int argc, char** argv)
{
	Test t1(1,2);

	if(t1.status())
	{
		cout << "t1.mi = " << t1.getI() << endl;
		cout << "t1.mj = " << t1.getJ() << endl;
	}
    return 0;
}
