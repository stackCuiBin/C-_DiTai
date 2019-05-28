/*************************************************************************
 ******* File Name: constructor_1.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 27 May 2019 07:27:30 AM PDT
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
private:
	int i;
	int j;

public:
	int getI() { return i; };
	int getJ() { return j; };
	Test()
	{
		cout << "call Test()" << endl;
		i = 1;
		j = 2;
	};
};

Test gt;

int main(int argc, char** argv)
{

	cout << "gt.i = " << gt.getI() << endl;	// no Test(): = 0
	cout << "gt.j = " << gt.getJ() << endl;	// = 0

	Test lt;
	cout << "lt.i = " << lt.getI() << endl;	// no Test(): = 随机值
	cout << "lt.j = " << lt.getJ() << endl;	// = 随机值

	Test* pt = new Test;
	cout << "pt->i = " << pt->getI() << endl;	// no Test(): = 随机值
	cout << "pt->j = " << pt->getJ() << endl;	// = 随机值
	delete pt;

    return 0;
}
