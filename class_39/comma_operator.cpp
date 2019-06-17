/*************************************************************************
 ******* File Name: comma_operator.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 17 Jun 2019 11:31:50 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
	int mValue;
public:
	Test(int v)
	{
		mValue = v;
	}
	int value()
	{
		return mValue;
	}
};

/*Test& operator , (const Test& a, const Test& b)
{
	return const_cast<Test&>(b);
}*/

Test func(Test& t)
{
	cout <<"func(Test t), t = " << t.value() << endl;

	return t;
}

int main(int argc, char** argv)
{
	Test t0(0);
	Test t1(1);
	Test tt = (func(t0), func(t1));	// 不是从左向右

	cout << "tt.value = " << tt.value() << endl;

    return 0;
}

/*
 * result:
 * func(Test t), t = 1
 * func(Test t), t = 0
 * tt.value = 1
 *
 * remove operator ,()
 * func(Test t), t = 0
 * func(Test t), t = 1
 * tt.value = 1
 *
 */
