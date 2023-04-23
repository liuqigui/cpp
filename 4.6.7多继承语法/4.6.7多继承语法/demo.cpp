/*
4.6.7多继承语法
C++允许一个类继承多个类
语法:class子类∶继承方式父类1,继承方式父类2..-
多继承可能会引发父类中有同名成员出现。需要加作用域区分
C++实际开发中不建议用多继承

*/

#include<iostream>

using namespace std;

//多继承语法
class Base1
{
public:

	Base1()
	{
		m_A = 100;
	}

	int m_A;
};

class Base2
{
public:
	
	Base2()
	{
		m_B = 200;
		m_A = 500;
	}

	int m_B;
	int m_A;
};

//子类 需要继承Base1和Base2
class Son :public Base1, public Base2
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}

	int m_C;
	int m_D;
};


void test01()
{

	Son s;
	cout << "sizeof(s):" << sizeof(s) << endl;

	cout << "s.Base1::m_A=" << s.Base1::m_A << endl;
	cout << "s.Base2::m_A=" << s.Base2::m_A << endl;

}

int main()
{
	cout << "多继承语法" << endl;
	test01();

	system("pause");
	return 0;
}



