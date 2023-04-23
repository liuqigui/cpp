/*
4.6.8菱形继承
菱形继承概念:
	两个派生类继承同一个基类
	又有某个类同时继承者两个派生类
	这种继承被称为菱形继承，或者钻石继承
典型的菱形继承案例:


菱形继承问题:
1.羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据时，就会产生二义性。
2草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以。

总结;
·菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
·利用虚继承可以解决菱形继承问题
*/

#include<iostream>

using namespace std;

//菱形继承
class Animal
{
public:
	int m_Age;
};

//利用虚继承 解决菱形继承的问题
//在继承之前加上关键字 virtual变为虚继承
//Animal类成为 虚基类
class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};


//羊类
//class Sheep :public Animal {};
//
//class Tuo :public Animal {};

class SheepTuo : public Sheep, public Tuo {};

void test01()
{
	SheepTuo st;
	st.Tuo::m_Age = 28;
	st.Sheep::m_Age = 17;

	//当菱形继承时，两个父类拥有相同数据 通过作用于加以区分
	cout << "st.Tuo::m_Age" << st.Tuo::m_Age << endl;
	cout << "st.Sheep::m_Age" << st.Sheep::m_Age << endl;

	cout << "st.m_Age" << st.m_Age << endl;
}

int main()
{
	cout << "菱形继承" << endl;
	test01();

	system("pause");
	return 0;
}