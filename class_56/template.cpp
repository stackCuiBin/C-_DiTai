/*************************************************************************
 ******* File Name: template.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 08 Jul 2019 10:06:10 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

template < typename T>
void Sort(T a[], int len)
{
	for(int i = 0; i < len; i++)
	{
		for(int j = i; j < len; j++)
		{
			if(a[i] > a[j])
			{
				T t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

template < typename T>
void Println(T a[], int len)
{
	for(int i = 0; i < len; i++)
	{
		cout << a[i] << ", ";
	}
	cout << endl;
}

int main(int argc, const char* argv[])
{
	int a[5] = {5, 3, 1, 4, 2};

	Println(a, 5);
	Sort(a, 5);
	Println(a, 5);

	string s[5] = {"Java", "C++", "Python", "Basic", "Ruby"};

	Println(s, 5);
	Sort(s, 5);
	Println(s, 5);

    return 0;
}
