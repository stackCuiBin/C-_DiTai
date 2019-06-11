/*************************************************************************
 ******* File Name: sstream.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 11 Jun 2019 10:46:41 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define TO_NUMBER(s, n)		(istringstream(s) >> n) 						// istringstream valid only in one statement
#define TO_STRING(n)		(((ostringstream&)(ostringstream() << n)).str())	// ostringstream valid only in one statement

/* not recommended */
bool to_number(string s, int& n)
{
	istringstream iss(s);

	return iss >> n;	// notice the return type
}

/* not recommended */
string to_string(int n)
{
	ostringstream oss;
	oss << n;

	return oss.str();
}

int main(int argc, char** argv)
{
	int num = 0;

	if(to_number("123", num))
	{
		cout << num << endl;
	}

	if(TO_NUMBER("12.3", num))
	{
		cout << num << endl;
	}

	ostringstream oss;
	oss << 54 << "." << 32;	// return type is ostringstream
	string s = oss.str();

	cout << s << endl;

	s = TO_STRING(num);
	cout << s << endl;

    return 0;
}

/*
 * result:
 * 123
 * 12
 * 54.32
 * 12
 */
