/*************************************************************************
 ******* File Name: string_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 11 Jun 2019 11:27:18 PM CST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

/* loop right shift */
string right_func(const string& s, unsigned int n)
{
	string ret = "";
	unsigned int pos = 0;

	n = n % s.length();
	pos = s.length() - n;
	ret = s.substr(pos);
	ret += s.substr(0, pos);

	return ret;
}

string operator >>(const string& s, unsigned int n)
{
	string ret = "";
	unsigned int pos = 0;

	n = n % s.length();
	pos = s.length() - n;
	ret = s.substr(pos);
	ret += s.substr(0, pos);

	return ret;
}

int main(int argc, char** argv)
{
	string s1 = right_func("abcdefg", 8);
	cout << s1 << endl;
	
	string s2 = "abcdefg";
	string s3 = (s2 >> 3);
	cout << s3 << endl;

    return 0;
}

/*
 * result:
 * gabcdef
 * efgabcd
 */
