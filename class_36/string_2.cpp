/*************************************************************************
 ******* File Name: string_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sat 15 Jun 2019 02:34:31 PM CST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

#define MODIFY

int main(int argc, char** argv)
{
#ifndef MODIFY
	const char* p = "12345";
	string s = "";

	s.reserve(10);

	for(int i = 0; i < 5; i++)
	{
		s[i] = p[i];
	}

	cout << s << endl;	// print NULL

	for(int i = 0; i < 5; i++)
	{
		cout << s[i] << endl;	// print 1, 2, 3, 4, 5
	}
#else
	string b = "12345";
	string s = "";

	s = b;

	cout << s << endl;	// print 12345

	for(int i = 0; i < 5; i++)
	{
		cout << s[i] << endl;	// print 1, 2, 3, 4, 5
	}

#endif

    return 0;
}
