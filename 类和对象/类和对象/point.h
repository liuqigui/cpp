#pragma once
#include<iostream>
using namespace std;

class Point {
public:
	void setX(int i);

	int getX();

	void setY(int i);

	int getY();

private:
	int x;
	int y;
};
