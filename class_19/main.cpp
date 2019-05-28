/*************************************************************************
 ******* File Name: main.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 27 May 2019 08:54:05 AM PDT
 ************************************************************************/

#include <iostream>
#include "IntArray.h"

using namespace std;

int main(int argc, char** argv)
{
	IntArray a(5);

	for(int i=0; i<a.length(); i++)
	{
		a.set(i, i+1);
	}

	for(int i=0; i<a.length(); i++)
	{
		int value = 0;

		if(a.get(i, value))
		{
			cout << "a[" << i <<"] = " << value << endl;
		}
	}

	IntArray b = a;
	for(int i=0; i<b.length(); i++)
	{
		int value = 0;

		if(b.get(i, value))
		{
			cout << "b[" << i <<"] = " << value << endl;
		}
	}

	b.free();
	a.free();
	
    return 0;
}
