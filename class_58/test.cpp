/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 10 Jul 2019 10:42:51 PM CST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

template < typename T >
class Operator
{
public:
	T add(T a, T b)
	{
		return a + b;
	}

	T minus(T a, T b)
	{
		return a - b;
	}

};

string operator -(string& s1, string& s2)
{
	return "minus";
}

int main(int argc, const char* argv[])
{
	Operator<int> op1;

	cout << op1.add(1, 2) << endl;
	cout << op1.minus(4, 3) << endl;

	Operator<string> op2;

	cout << op2.add("chi", " tang") << endl;
	cout << op2.minus("chi", " tang") << endl;

    return 0;
}
