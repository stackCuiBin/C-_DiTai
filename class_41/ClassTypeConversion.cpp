/*************************************************************************
 ******* File Name: ClassTypeConversion.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 20 Jun 2019 10:55:07 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
	int mValue;
public:
	Test()
	{
		mValue = 0;
	}

	explicit Test(int i)
	{
		mValue = i;
	}

	Test operator + (const Test& obj)
	{
		Test ret(mValue + obj.mValue);

		return ret;
	}

	int value()
	{
		return mValue;
	}
};

int main(int argc, char** argv)
{
	Test t;

	//t = 5;	// t = Test(5); 编译器会隐式类型转换
	//t = (Test)5;	// 不推荐
	t = static_cast<Test>(5);
	cout << t.value() << endl;

	Test tt;

	//tt = t + (Test)10;	// tt = t + Test(10);
	tt = t + static_cast<Test>(10);
	cout << tt.value() << endl;

    return 0;
}
