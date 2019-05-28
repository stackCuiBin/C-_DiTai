/*************************************************************************
 ******* File Name: InitializationList_1.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 28 May 2019 11:08:13 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
private:
	const int ci;
public:
	Test() : ci(10)
	{
		//ci = 10;
	}
	int getCI()
	{
		return ci;
	}
};

int main(int argc, char** argv)
{
	Test t;

	cout << "t.ci = " << t.getCI() << endl;

    return 0;
}
