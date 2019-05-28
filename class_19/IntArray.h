/*************************************************************************
 ******* File Name: IntArray.h
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 27 May 2019 08:37:20 AM PDT
 ************************************************************************/

#ifndef __INTARRAY_H_
#define __INIARRAY_H_

class IntArray
{
private:
	int m_length;
	int* m_pointer;

public:
	IntArray(int len);
	IntArray(const IntArray& obj);
	int length();
	bool get(int index, int& value);
	bool set(int index, int value);
	void free();
};

#endif
