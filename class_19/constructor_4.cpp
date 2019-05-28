/*************************************************************************
 ******* File Name: constructor_4.cpp
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
	int *p;
public:
	int getI()
	{
		return i;
	}
	int getJ()
	{
		return j;
	}
	int* getP()
	{
		return p;
	}
	Test(const Test& t)
	{
		i = t.i;
		j = t.j;
		p = new int;

		*p = *t.p;
	}
	Test(int v)
	{
		i = 1;
		j = 2;
		p = new int;

		*p = v;
	}
	void free()
	{
		delete p;
	}
};

int main(int argc, char** argv)
{

	Test t1(3);
	Test t2(t1);

	cout << "t1.i = " << t1.getI() << ", t1.j = " << t1.getJ() << ", *t1.p = " << *t1.getP() << ", t1.p = " << t1.getP() << endl;
	cout << "t2.i = " << t2.getI() << ", t2.j = " << t2.getJ() << ", *t2.p = " << *t2.getP() << ", t2.p = " << t2.getP() << endl;

	t1.free();
	t2.free();

    return 0;
}

/*
 * result:
 * t1.i = 1, t1.j = 2, *t1.p = 3, t1.p = 0x102dc20
 * t2.i = 1, t2.j = 2, *t2.p = 3, t2.p = 0x102dc40
 */
