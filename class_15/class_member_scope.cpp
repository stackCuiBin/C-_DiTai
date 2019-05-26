/*************************************************************************
 ******* File Name: class_member_scope.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 26 May 2019 06:25:31 AM PDT
 ************************************************************************/

#include <iostream>

using namespace std;

int i = 1;

struct Test
{
private:
	int i;

public:
	int j;

	int getI()
	{
		i = 3;

		return i;
	}
};

int main(int argc, char** argv)
{
	int i = 2;
	Test test;

	test.j = 4;


	cout << "i = " << i << endl;
	cout << "::i = " << ::i << endl;
	//cout << "test.i = " << test.i << endl;	// error
	cout << "test.j = " << test.j << endl;
	cout << "test.getI() = " << test.getI() << endl;

	return 0;
}

/*
 * result:
 * i = 2
 * ::i = 1
 * test.j = 4
 * test.getI() = 3
 */
