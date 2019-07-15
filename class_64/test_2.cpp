/*************************************************************************
 ******* File Name: test_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 14 Jul 2019 06:42:30 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

void demo()
{
	try
	{
		throw 1;
		throw 'c';
	}
	catch(char c)
	{
		cout << "catch(char c)" << endl;
	}
	catch(short c)
	{
		cout << "catch(short c)" << endl;
	}
	catch(double c)
	{
		cout << "catch(double c)" << endl;
	}
	catch(int c)
	{
		cout << "catch(int c)" << endl;
	}
	catch(...)	// must be last
	{
		cout << "catch(...)" << endl;
	}
}

void demo2()
{
	//throw "chitang";			// catch(const char* cs)
	throw string("chitang");	// catch(string s)
}

int main(int argc, const char* argv[])
{
	demo();

	try
	{
		demo2();
	}
	catch(char* c)
	{
		cout << "catch(char* c)" << endl;
	}
	catch(const char* cs)
	{
		cout << "catch(const char* cs)" << endl;
	}
	catch(string s)
	{
		cout << "catch(string s)" << endl;
	}

    return 0;
}
