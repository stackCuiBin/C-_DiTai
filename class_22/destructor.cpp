/*************************************************************************
 ******* File Name: destructor.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 29 May 2019 11:30:12 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
	int mi;
public:
	Test(int v)
	{
		mi = v;
		cout << "Test(): mi = " << mi << endl;
	}
	~Test()
	{
		cout << "~Test(): mi = " << mi << endl;
	}
};

int main(int argc, char** argv)
{

	Test t(1);
	Test* pt = new Test(2);

	delete pt;	// without this statement, ~Test() will not be called 

    return 0;
}
