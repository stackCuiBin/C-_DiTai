/*************************************************************************
 ******* File Name: const_func.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 04 Jun 2019 10:29:32 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
	int mi;
public:
	Test(int i);
	Test(const Test& t);
	int getMI()const;
};

Test::Test(int i)
{
	mi = i;
}

Test::Test(const Test& t)
{
	mi = t.getMI();
}

int Test::getMI()const 
{
	return mi;
}

int main(int argc, char** argv)
{
	const Test t(1);

	cout << "t.mi = " << t.getMI() << endl;

    return 0;
}
