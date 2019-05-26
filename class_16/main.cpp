/*************************************************************************
 ******* File Name: main.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 26 May 2019 07:48:23 AM PDT
 ************************************************************************/

#include <iostream>
#include "Operator.h"

using namespace std;

int main(int argc, char** argv)
{
	Operator op;
	double r;

	op.setOperator('/');
	op.setParameter(9, 3);

	if( op.result(r) )
	{
		cout << "r = " << r << endl;
	}
	else
	{
		cout << "Calculate error!" << endl;
	}

    return 0;
}
