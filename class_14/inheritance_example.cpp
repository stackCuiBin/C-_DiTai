/*************************************************************************
 ******* File Name: inheritance_example.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Fri 24 May 2019 11:00:09 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

struct Biology
{
	bool living;
};

struct Animal : Biology
{
	bool movable;
	void fundFood() {}
};

struct Plant : Biology
{
	bool growable;
};

struct Beast : Animal
{
	void sleep() {}
};

struct Human : Animal
{
	void sleep() {}
	void work() {}
};

int main(int argc, char** argv)
{
	return 0;
}

