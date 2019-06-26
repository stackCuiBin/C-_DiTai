/*************************************************************************
 ******* File Name: demo.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 26 Jun 2019 11:08:30 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Object
{
protected:
	string mName;
	string mInfo;

public:
	Object()
	{
		mName = "Object";
		mInfo = "";
	}

	string name()
	{
		return mName;
	}

	string info()
	{
		return mInfo;
	}
};

class Point : public Object
{
private:
	int mX;
	int mY;

public:
	Point(int x = 0, int y = 0)
	{
		ostringstream s;

		mX = x;
		mY = y;

		mName = "Point";

		s << "Point(" << mX << ", " << mY << ")";

		mInfo = s.str();
	}

	int x()
	{
		return mX;
	}

	int y()
	{
		return mY;
	}
};

class Line : public Point
{
private:
	Point mP1;
	Point mP2;

public:
	Line(Point p1, Point p2)
	{
		ostringstream s;

		mP1 = p1;
		mP2 = p2;

		mName = "Line";

		s << "Line from " << mP1.info() << " to " << mP2.info();

		mInfo = s.str();
	}
};

int main(int argc, char** argv)
{
	Point p1(1, 2);
	Point p2(3, 4);
	
	cout << p1.name() << endl;
	cout << p1.info() << endl;

	cout << endl;

	Line l(p1, p2);

	cout << l.name() << endl;
	cout << l.info() << endl;

    return 0;
}
