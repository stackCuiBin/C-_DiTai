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

	if(a != NULL)
	{
		IntArray& array = a->self();

		cout << "array.length() = " << array.length() << endl;

		array[0] = 1;

		for(int i = 0; i < array.length(); i++)
		{
			cout << array[i] << endl;
		}
	}

	delete a;

    return 0;
}
