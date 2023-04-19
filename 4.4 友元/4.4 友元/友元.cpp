/*
4.4友元
生活中你的家有客厅(Public)，有你的卧室(Private)
客厅所有来的客人都可以进去，但是你的卧室是私有的,也就是说只有你能进去但是呢，你也可以允许你的好闺蜜好基友进去。
在程序里，有些私有属性也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术
友元的目的就是让一个函数或者类访问另一个类中私有成员
友元的关键字为	friend
友元的三种实现
·全局函数做友元
·类做友元
·成员函数做友元

*/

#include<iostream>
#include<string>

using namespace std;

//建筑物类
class Building {

	//goodGay全局函数是Building好朋友，可以访问Building中私有成员
	friend void goodGay(Building &building);

public:
	Building() {
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}

public:
	string m_SittingRoom;	//客厅

private:
	string m_BedRoom;
};

//全局函数
void goodGay(Building &building) {
	cout << "好基友的全局函数，正在访问：" << building.m_SittingRoom << endl;

	cout << "好基友的全局函数，正在访问：" << building.m_BedRoom << endl;

}

void test01() {
	Building b;
	goodGay(b);
}

//类做友元
class Building1;

class GoodGay {
public:
	GoodGay();
	void visit();	//参观函数 访问Building中的属性
	Building1 * building;
};

class Building1 {
	//GoodGay类是本类的好朋友，可以访问本类的私有成员
	friend class GoodGay;

public:
	Building1();

public:
	string m_SittingRoom;	//客厅
private:
	string m_BedRoom;
};

//类外写成员构造函数
Building1::Building1() {
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay() {
	//创建建筑物对象
	building = new Building1;
}

void GoodGay::visit() {
	cout << "好基友类正在访问：" << building->m_SittingRoom << endl;

	cout << "好基友类正在访问：" << building->m_BedRoom << endl;

}

void test02() {
	GoodGay gg;
	gg.visit();
}

//成员函数做友元
class Building2;
class GoodGay2 {
public:
	GoodGay2();

	void visit();	//让visit函数可以访问Building2中私有成员
	void visit2();	//让visit2函数不可以访问Building2中私有成员

	Building2 * building2;
};

class Building2 {
	friend void GoodGay2::visit();

public:
	Building2();

public:
	string m_SittingRoom;	//客厅

private:
	string m_BedRoom;	//卧室
};

Building2::Building2() {
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay2::GoodGay2() {
	building2 = new Building2;
}

void GoodGay2::visit() {
	cout << "好基友类正在访问：" << building2->m_SittingRoom << endl;
	cout << "好基友类正在访问：" << building2->m_BedRoom << endl;

}

void GoodGay2::visit2() {
	cout << "好基友类正在访问：" << building2->m_SittingRoom << endl;
	//cout << "好基友类正在访问：" << building2->m_BedRoom << endl;

}

void test03() {
	GoodGay2 gg;
	gg.visit();
	gg.visit2();
}

int main() {

	cout << "4.4友元" << endl;
	//test01();

	cout << "类做友元" << endl;
	//test02();

	cout << "成员函数做友元" << endl;
	test03();


	system("pause");
	return 0;
}