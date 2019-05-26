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

struct Girl : Human
{
private:
	int age;
	int weight;

public:
	void print()
	{
		age = 22;
		weight = 48;

		cout << "I'm a girl, I'm " << age << " years old." << endl;
		cout << "My weight is " << weight << " kg." << endl;
	}
};

struct Boy : Human
{
private:
	int height;
	int salary;

public:
	int age;
	int weight;

	void print()
	{
		height = 175;
		salary = 9000;

		cout << "I'm a boy, my height is " << height << " cm."<< endl;
		cout << "My salary is " << salary << " RMB."<< endl;
	}
};

int main(int argc, char** argv)
{
	Girl g;
	Boy b;

	g.print();
	b.print();
	return 0;
}

