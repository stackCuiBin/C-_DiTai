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
	IntArray* b = IntArray::NewInstance(10);

	if(a && b)
	{
		IntArray& array = a->self();
		IntArray& brray = b->self();

		cout << "array.length() = " << array.length() << endl;
		cout << "brray.length() = " << brray.length() << endl;

		array = brray;

		cout << "array.length() = " << array.length() << endl;
		cout << "brray.length() = " << brray.length() << endl;
	}

	delete a;
	delete b;

    return 0;
}
