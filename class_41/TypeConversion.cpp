/*************************************************************************
 ******* File Name: TypeConversion.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 20 Jun 2019 10:27:33 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	short s = 'a';
	unsigned int ui = 1000;
	int i = -2000;
	double d = i;

	cout << "d = " << d <<endl;
	cout << "ui = " << ui << endl;
	cout << "ui + i = " << ui + i << endl;

	/* 把i隐式转换为了unsigned int */
	if( (ui + i) > 0 )
	{
		cout << "Positive" << endl;
	}
	else 
	{
		cout << "Negative" << endl;
	}

	cout << "sizeof(short) = " << sizeof(short) << endl;
	cout << "sizeof(int) = " << sizeof(int) << endl;
	/* 编译器优化，4个字节操作更高效，把short隐式转换为int，char隐式转换为int */
	cout << "sizeof(s + 'b') = " << sizeof(s + 'b') << endl;

    return 0;
}

/*
 * result:
 * d = -2000
 * ui = 1000
 * ui + i = 4294966296
 * Positive
 * sizeof(short) = 2
 * sizeof(int) = 4
 * sizeof(s + 'b') = 4
 */
