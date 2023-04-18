/*
练习案例1:设计立方体类
设计立方体类(Cube)
求出立方体的面积和体积
分别用全局函数和成员函数判断两个立方体是否相等。
*/

#include<iostream>

using namespace std;

class Cube {
public:
	//设置长
	void set_L(int l) {
		m_L = l;
	}

	//获取长
	int get_L() {
		return m_L;
	}

	//设置宽
	void set_W(int w) {
		m_W = w;
	}

	//获取宽
	int get_W() {
		return m_W;
	}

	//设置高
	void set_H(int h) {
		m_H = h;
	}

	//获取高
	int get_H() {
		return m_H;
	}

	//获取面积
	int calculateS() {
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}

	//获取体积
	int calculateV() {
		return m_L * m_W * m_H;
	}

	//利用全局函数判断两个立方体是否相等
	bool isSameByClass(Cube &c) {
		if (m_L == c.get_L() && m_W == c.get_W() && m_H == c.get_H()) {
			return 1;
		}
		else {
			return 0;
		}

	}
private :
	int m_L;	//长
	int m_W;	//宽
	int m_H;	//高
};

//利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1, Cube &c2) {
	if (c1.get_L() == c2.get_L() && c1.get_W() == c2.get_W() && c1.get_H() == c2.get_H()) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {

	Cube c1;
	c1.set_L(10);
	c1.set_W(10);
	c1.set_H(10);

	cout << "c1的面积：" << c1.calculateS() << endl;
	cout << "c1的体积：" << c1.calculateV() << endl;

	Cube  c2;
	c2.set_L(10);
	c2.set_W(10);
	c2.set_H(10);

	bool ret = isSame(c1, c2);
	if (ret) {
		cout << "c1和c2是相等的！" << endl;
	}
	else {
		cout << "c1和c2不是相等的！" << endl;
	}

	bool  ret1 = c1.isSameByClass(c2);
	if (ret1) {
		cout << "类内函数c1和c2是相等的！" << endl;
	}
	else {
		cout << "类内函数c1和c2不是相等的！" << endl;
	}

	system("pause");
	return 0;
}