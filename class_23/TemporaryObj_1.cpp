/*************************************************************************
 ******* File Name: TemporaryObj_1.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 30 May 2019 08:42:09 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
private:
	int mi;
	void init(int v)
	{
		mi = v;
	}
public:
	Test(int val)
	{
		cout << "Test(int val)" << endl;
		init(val);
	}
	Test()
	{
		cout << "Test()" << endl;
		//Test(0);	//从运行结果来看产生临时对象，生命周期只在这一行
		init(0);
	}
	int getMI()
	{
		return mi;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
};

int main(int argc, char** argv)
{
	Test t;

	cout << "t.mi = " << t.getMI() << endl;

    return 0;
}

/*
 * result:
 *
 * 1)compile with Test(0)
 * Test()
 * Test(int val)
 * ~Test()
 * t.mi = 4197392
 * ~Test()
 *
 * 2)compile with init(0)
 * Test()
 * t.mi = 0
 * ~Test()
 */
