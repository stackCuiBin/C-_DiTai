/*************************************************************************
 ******* File Name: constructor_3.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 28 May 2019 06:43:44 AM PDT
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
private:
	int i;
	int j;

public:
	int getI()
	{
		return i;
	}
	int getJ()
	{
		return j;
	}
	Test(const Test& t)
	{
		i = t.i;
		j = t.j;
	}
	Test()
	{
	}
};

int main(int argc, char** argv)
{

	Test t1;
	Test t2 = t1;

	cout << "t1.i = " << t1.getI() << ", t1.j = " << t1.getJ() << endl;
	cout << "t2.i = " << t2.getI() << ", t2.j = " << t2.getJ() << endl;

    return 0;
}
