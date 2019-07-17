/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 17 Jul 2019 10:14:02 PM CST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

template
< class T >
class Test
{
public:
	Test(T t)
	{
		cout << "t = " << t << endl;
	}
};

template
< class T >
void func(T t[], int len)
{
	for(int i = 0; i < len; i++)
	{
		cout << t[i] << endl;
	}
}


int main(int argc, const char* argv[])
{
	Test<string> Ts("chitang");
	string ts[] = {"A", "B", "C"};

	func(ts, 3);

	Test<int> Ti(100);
	int ti[] = {1, 2, 3};

	func(ti, 3);

    return 0;
}

/*
 * result:
 * t = chitang
 * A
 * B
 * C
 * t = 100
 * 1
 * 2
 * 3
 */
