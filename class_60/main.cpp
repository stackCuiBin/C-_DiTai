/*************************************************************************
 ******* File Name: main.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 11 Jul 2019 09:59:36 PM CST
 ************************************************************************/

#include <iostream>
#include "Array.h"

using namespace std;

int main(int argc, const char* argv[])
{
	Array<double, 5> ad;

	for(int i = 0; i < ad.length(); i++)
	{
		ad[i] = i;
	}

	for(int i = 0; i < ad.length(); i++)
	{
		cout << ad[i] << endl;
	}

    return 0;
}
