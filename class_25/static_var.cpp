/*************************************************************************
 ******* File Name: static_var.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 05 Jun 2019 10:32:26 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
private:
	static int count;
public:
	Test()
	{
		++count;
	}
	~Test()
	{
		--count;
	}
	int getCount()
	{
		return count;
	}
};

int Test::count = 0;

Test gt;

int main(int argc, char** argv)
{

	Test t1;
	Test t2;

	cout << "count = " << t1.getCount() << endl;
	cout << "count = " << t2.getCount() << endl;
	cout << "count = " << gt.getCount() << endl;

	Test *pt = new Test;

	cout << "count = " << pt->getCount() << endl;

	delete pt;

	cout << "count = " << gt.getCount() << endl;

    return 0;
}

/*
 * result:
 * count = 3
 * count = 3
 * count = 3
 * count = 4
 * count = 3
 */
