#pragma once


#include<iostream>

using namespace std;

#include "point.h"
//Ô²Àà
class Circle {
public:
	void setR(int r); 

	int getR(); 

	void setCenter(Point center);

	Point getCenter();

private:
	int m_R;	//°ë¾¶

	Point m_Center;		//Ô²ÐÄ
};