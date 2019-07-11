/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 11 Jul 2019 09:39:43 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

template
< typename T, int N>
void func()
{
	T a[N];

	for(int i = 0; i < N; i++)
	{
		a[i] = i;
	}

	for(int i = 0; i < N; i++)
	{
		cout << a[i] << endl;
	}
};

template 
< int N >
class Sum
{
public:
	static const int VALUE = Sum<N-1>::VALUE + N;
};

template
< >
class Sum<1>
{
public:
	static const int VALUE = 1;
};

int main(int argc, const char* argv[])
{
	func<int, 10>();

	cout << "1 + 2 + 3 + ... + 10 = " << Sum<10>::VALUE << endl;

    return 0;
}
