/*************************************************************************
 ******* File Name: ArrayOperatorOverload.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 12 Jun 2019 10:47:50 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
	int a[3];
public:
	int& operator [] (int i)
	{
		return a[i];
	}

	int& operator [] (const string& s)
	{
		if(s == "1st")
		{
			return a[0];
		}
		else if(s == "2nd")
		{
			return a[1];
		}
		else if(s == "3rd")
		{
			return a[2];
		}

		return a[0];
	}

	int length()
	{
		return 3;
	}
};

int main(int argc, char** argv)
{
	Test t;

	for(int i = 0; i<t.length(); i++)
	{
		t[i] = i;
	}

	for(int i = 0; i < t.length(); i++)
	{
		cout << t[i] << endl;
	}
	cout << endl;

	cout << t["3rd"] << endl;
	cout << t["2nd"] << endl;
	cout << t["1st"] << endl;

    return 0;
}

/*
 * result:
 * 0
 * 1
 * 2
 *
 * 2
 * 1
 * 0
 */
