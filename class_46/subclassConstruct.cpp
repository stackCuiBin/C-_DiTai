/*************************************************************************
 ******* File Name: subclassConstruct.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 27 Jun 2019 09:51:02 PM CST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Object
{
	string ms;
public:
	Object(string s)
	{
		cout << "Object(string s) : " << s << endl;
		ms = s;
	}

	~Object()
	{
		cout << "~Object() : " << ms << endl;
	}
};

class Parent : public Object
{
	string ms;
public:
	Parent() : Object("Default")
	{
		cout << "Parent()" << endl;
		ms = "Default";
	}
	Parent(string s) : Object(s)
	{
		cout << "Parent(string s) : " << s << endl;
		ms = s;
	}

	~Parent()
	{
		cout << "~Parent() : " << ms << endl;
	}
};

class Child : public Parent
{
	Object mo1;
	Object mo2;
	string ms;
public:
	Child() : mo1("Default 1"), mo2("Default 2")
	{
		cout << "Child()" << endl;
		ms = "Default";
	}
	Child(string s) : Parent(s), mo1(s + " 1"), mo2(s + " 2")
	{
		cout << "Child(string s) : " << s << endl;
		ms = s;
	}

	~Child()
	{
		cout << "~Child() : " << ms << endl;
	}

};

int main(int argc, char** argv)
{
	Child c1("c1");

	cout << endl;
	cout << endl;

	Child c2;
	
	cout << endl;
	cout << endl;

    return 0;
}

/*
 * result:
 * Object(string s) : c1
 * Parent(string s) : c1
 * Object(string s) : c1 1
 * Object(string s) : c1 2
 * Child(string s) : c1
 *
 *
 * Object(string s) : Default
 * Parent()
 * Object(string s) : Default 1
 * Object(string s) : Default 2
 * Child()
 *
 *
 * ~Child() : Default
 * ~Object() : Default 2
 * ~Object() : Default 1
 * ~Parent() : Default
 * ~Object() : Default
 * ~Child() : c1
 * ~Object() : c1 2
 * ~Object() : c1 1
 * ~Parent() : c1
 * ~Object() : c1
 */
