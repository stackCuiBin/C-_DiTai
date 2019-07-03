/*************************************************************************
 ******* File Name: interface.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 03 Jul 2019 11:06:49 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Channel
{
public:
	virtual bool open() = 0;
	virtual void close() = 0;
	virtual bool send(char* buf, int len) = 0;
	virtual int receive(char* buf, int len) = 0;
};

int main(int argc, const char* argv[])
{

    return 0;
}
