/*************************************************************************
 ******* File Name: main.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Fri 07 Jun 2019 11:34:00 PM CST
 ************************************************************************/

#include <iostream>
#include "IntArray.h"

using namespace std;

int main(int argc, char** argv)
{
	IntArray* a = IntArray::NewInstance(5);

	cout << "a.length = " << a->length() << endl;

	a->set(0, 1);

	for(int i = 0; i < a->length(); i++)
	{
		int v = 0;

		a->get(i, v);

		cout << "a[" << i << "] = " << v << endl;
	}

	delete a;

    return 0;
}
