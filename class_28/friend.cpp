/*************************************************************************
 ******* File Name: friend.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sat 08 Jun 2019 10:13:04 AM CST
 ************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

class Point
{
	double x;
	double y;
public:
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	friend double func(Point& p1, Point& p2); 
};

double func(Point& p1, Point& p2)
{
	double ret = 0;

	//ret = (p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) +
	//	  (p1.getY() - p2.getY()) * (p1.getY() - p2.getY());
	ret = (p1.x - p2.x) * (p1.x - p2.x) +
		  (p1.y - p2.y) * (p1.y - p2.y);
	ret = sqrt(ret);

	return ret;
}


int main(int argc, char** argv)
{
	Point p1(1, 2);
	Point p2(10, 20);

	cout << "p1(" << p1.getX() << ", " << p1.getY() <<  ")" << endl;
	cout << "p2(" << p2.getX() << ", " << p2.getY() << ")" << endl;
	cout << "|(p1, p2)| = " << func(p1, p2) << endl;	

    return 0;
}
