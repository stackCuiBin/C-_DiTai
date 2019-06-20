/*************************************************************************
 ******* File Name: OperatorType.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 20 Jun 2019 11:14:51 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test;

class Value
{
public:
	Value()
	{
	}

	explicit Value(Test& t)	// 加explicit关键字是防止和Test类中的value类型转换冲突，为了编译通过
	{
	}
};

class Test
{
	int mValue;
public:
	Test(int i = 0)
	{
		mValue = i;
	}

	int value()
	{
		return mValue;
	}

	/* 工程中不推荐这种写法 */
	/*operator int ()
	{
		return mValue;
	}

	operator Value()
	{
		Value ret;
		cout << "operator Value() " << endl;

		return ret;
	}*/

	int toInt()
	{
		return mValue;
	}

	Value toValue()
	{
		Value ret;

		return ret;
	}
};


int main(int argc, char** argv)
{
	Test t(100);
	/* 隐式类型转换，不推荐 */
	//int i = t;	// int i = t.operator int()
	int i = t.toInt();

	cout << "t.value = " << t.value() << endl;
	cout << "i = " << i << endl;

	//Value v = t;
	Value v = t.toValue();

    return 0;
}
