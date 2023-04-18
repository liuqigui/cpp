/*
点和圆的关系
点到圆心的距离 == 半径 点在圆上
点到圆心的距离 >  半径 点在圆上
点到圆心的距离 <  半径 点在圆上
点到圆心的距离 == 0   点在圆心


*/

#include<iostream>
#include "point.h"
#include "circle.h"

using namespace std;

//点类
//class Point {
//public:
//	void setX(int i) {
//		x = i;
//	}
//
//	int getX() {
//		return x;
//	}
//
//	void setY(int i) {
//		y = i;
//	}
//
//	int getY() {
//		return y;
//	}
//
//private:
//	int x;
//	int y;
//};

////圆类
//class Circle {
//public:
//	void setR(int r) {
//		m_R = r;
//	}
//
//	int getR() {
//		return m_R;
//	}
//
//	void setCenter(Point center) {
//		m_Center = center;
//	}
//	Point getCenter() {
//		return m_Center;
//	}
//
//private:
//	int m_R;	//半径
//
//	Point m_Center;		//圆心
//};

//判断点和圆的关系
void isInCircle(Circle &c, Point &p) {
	//计算两点距离的平方
	int distance = (c.getCenter().getX() - p.getX())*(c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY())*(c.getCenter().getY() - p.getY());

	//计算半径的平方
	int rDistance = c.getR() * c.getR();

	if (distance > rDistance) {
		cout << "点在圆外" << endl;
	}
	else if (distance == rDistance) {
		cout << "点在圆上" << endl;

	}
	else {
		cout << "点在圆内" << endl;

	}
}

int main() {
	Circle c;
	c.setR(10);
	Point center;
	center.setX(0);
	center.setY(0);
	c.setCenter(center);

	Point p;
	p.setX(6);
	p.setY(8);

	isInCircle(c, p);

	Circle c1;
	c1.setR(10);
	Point center1;
	center1.setX(0);
	center1.setY(0);
	c1.setCenter(center1);

	Point p1;
	p1.setX(46);
	p1.setY(8);

	isInCircle(c1, p1);


	system("pause");
	return 0;
}