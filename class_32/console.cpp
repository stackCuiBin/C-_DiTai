/*************************************************************************
 ******* File Name: console.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 11 Jun 2019 09:32:01 PM CST
 ************************************************************************/

#include <stdio.h>

const char endl = '\n';

class Console
{
public:
	Console& operator << (int i)
	{
		printf("%d", i);

		return *this;
	}

	Console& operator << (const char c)
	{
		printf("%c", c);

		return *this;
	}

	Console& operator << (double d)
	{
		printf("%f", d);

		return *this;
	}

	Console& operator << (const char* s)
	{
		printf("%s", s);

		return *this;
	}
};

Console cout;

int main(int argc, char** argv)
{
	cout << 1 << endl;
	cout << "good luck" << endl;

	double d = 0.1;
	cout << d << endl;

    return 0;
}
