/*************************************************************************
 ******* File Name: construction.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 30 May 2019 10:26:01 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Member
{
	const char* ms;
public:
	Member(const char* s)
	{
		cout << "Member(const char* s): " << s << endl;
		ms = s;
	}
	~Member()
	{
		cout << "~Member(): " << ms << endl;
	}
};

class Test
{
	Member mA;
	Member mB;
public:
	Test():mB("mB"),mA("mA")
	{
		cout << "Test()" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
};

Member gA("gA");

int main(int argc, char** argv)
{

	Test t;

    return 0;
}

/*
 * result:
 * Member(const char* s): gA
 * Member(const char* s): mA
 * Member(const char* s): mB
 * Test()
 * ~Test()
 * ~Member(): mB
 * ~Member(): mA
 * ~Member(): gA
 */
