/*************************************************************************
 ******* File Name: logical_operator.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 17 Jun 2019 10:45:57 PM CST
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
	int value() const
	{
		return mValue;
	}
};

bool operator && (const Test& l, const Test& r)
{
	return l.value() && r.value();
}

bool operator || (const Test& l, const Test& r)
{
	return l.value() || r.value();
}

Test func(Test t)
{
	cout << "func(Test t): t.value = " << t.value() << endl;

	return t;
}

int main(int argc, char** argv)
{
	Test t0(0);
	Test t1(1);

	//if(operator && (func(t0), func(t1)))
	if(func(t0) && func(t1))
	{
		cout << "Result is true" << endl;
	}
	else
	{
		cout << "Result is false" << endl;
	}

	//if(operator || (func(0), func(1)))
	if(func(0) || func(1))
	{
		cout << "Result is true" << endl;
	}
	else
	{
		cout << "Result is false" << endl;
	}
	
    return 0;
}

/*
 * result:
 * func(Test t): t.value = 1
 * func(Test t): t.value = 0
 * Result is false
 * func(Test t): t.value = 1
 * func(Test t): t.value = 0
 * Result is true
 */
