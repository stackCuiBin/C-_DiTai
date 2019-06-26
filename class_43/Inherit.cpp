/*************************************************************************
 ******* File Name: Inherit.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 24 Jun 2019 10:45:48 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Memory
{
public:
	Memory()
	{
		cout << "Memory()" << endl;
	}
	~Memory()
	{
		cout << "~Memory()" << endl;
	}
};

class Disk
{
public:
	Disk()
	{
		cout << "Disk()" << endl;
	}
	~Disk()
	{
		cout << "~Disk()" << endl;
	}
};

class CPU
{
public:
	CPU()
	{
		cout << "CPU()" << endl;
	}
	~CPU()
	{
		cout << "~CPU()" << endl;
	}
};

class MainBoard
{
public:
	MainBoard()
	{
		cout << "MainBoard()" << endl;
	}
	~MainBoard()
	{
		cout << "~MainBoard()" << endl;
	}
};

class Computer
{
	Memory mMem;
	Disk mDisk;
	CPU mCPU;
	MainBoard mMainBoard;
public:
	Computer()
	{
		cout << "Computer()" << endl;
	}
	void power()
	{
		cout << "power()" << endl;
	}
	void reset()
	{
		cout << "reset()" << endl;
	}
	~Computer()
	{
		cout << "~Computer()" << endl;
	}
};

class HPBook : public Computer
{
	string mOS;
public:
	HPBook()
	{
		mOS = "Windows 8";
	}

	void install(string os)
	{
		mOS = os;
	}
	
	void OS()
	{
		cout << mOS << endl;
	}
};

class MacBook : public Computer
{
public:
	void OS()
	{
		cout << "Mac OS" << endl;
	}
};

int main(int argc, char** argv)
{
	HPBook hp;

	hp.power();
	hp.install("UBUNTU");
	hp.OS();

	cout << endl;

	MacBook mac;

	mac.OS();

	cout << endl;

    return 0;
}
