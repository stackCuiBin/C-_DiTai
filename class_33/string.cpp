/*************************************************************************
 ******* File Name: string.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 11 Jun 2019 10:20:13 PM CST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

void string_sort(string a[], int len)
{
	for(int i = 0; i < len; i++)
	{
		for(int j = i; j < len; j++)
		{
			if(a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

string string_add(string a[], int len)
{
	string ret = "";

	for(int i = 0; i < len; i++)
	{
		ret += a[i] + ";";
	}

	return ret;
}

int main(int argc, char** argv)
{
	string sa[7] = 
	{
		"Good lock!",
		"Hello world!",
		"C#",
		"Java",
		"C++",
		"Python",
		"JavaScript"
	};

	string_sort(sa, 7);

	for(int i = 0; i<7; i++)
	{
		cout << sa[i] << endl;
	}

	cout << string_add(sa, 7) << endl;

    return 0;
}
