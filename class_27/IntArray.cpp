/*************************************************************************
 ******* File Name: IntArray.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Fri 07 Jun 2019 11:18:06 PM CST
 ************************************************************************/

#include "IntArray.h"

IntArray::IntArray(int len)
{
	m_length = len;
	m_pointer = 0;
}

IntArray::~IntArray()
{
	if(m_pointer)
	{
		delete m_pointer;
	}
}

bool IntArray::construct()
{
	bool ret = true;

	m_pointer = new int[m_length];

	if(m_pointer)
	{
		for(int i = 0; i < m_length; i++)
		{
			m_pointer[i] = 0;
		}
	}
	else
	{
		ret = false;
	}

	return ret;
}

IntArray* IntArray::NewInstance(int len)
{
	IntArray* ret = new IntArray(len);

	if(!(ret && ret->construct()))
	{
		delete ret;
		ret = 0;
	}

	return ret;
}

int IntArray::length()
{
	return m_length;
}

bool IntArray::get(int index, int& value)
{
	bool ret = (0 <= index) && (index < length());

	if(ret)
	{
		value = m_pointer[index];
	}

	return ret;
}

bool IntArray::set(int index, int value)
{
	bool ret = (0 <= index) && (index < length());

	if(ret)
	{
		m_pointer[index] = value;
	}

	return ret;
}
