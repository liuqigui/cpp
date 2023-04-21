/*
4.6.5继承同名成员处理方式
问题:当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢?
·访问子类同名成员 直接访问即可
·访问父类同名成员 需要加作用域

总结:
1.子类对象可以直接访问到子类中同名成员
2.子类对象加作用域可以访问到父类同名成员
3.当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
*/

#include<iostream>

using namespace std;

//继承同名成员处理方式
class Base
{
public:
	Base()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base-func()函数调用" << endl;
	}

	void func(int a)
	{
		cout << "Base-func()函数调用" << a << endl;
	}

	int m_A;
};

class Son :public Base
{
public:
	Son()
	{
		m_A = 200;
	}

	void func()
	{
		cout << "Son-func()函数调用" << endl;
	}

	int m_A;
};

//同名属性
void test01()
{
	Son s;
	cout << "Son.m_A = " << s.m_A << endl;

	// 如果通过子类对象访问到父类中同名成员，需要加作用域
	cout << "Base.m_A = " << s.Base::m_A << endl;

}

//同名函数
void test02()
{
	Son s1;
	s1.func();

	//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
	//如果想访问到父类中被隐藏的同名成员函数，需要加作用域
	//s1.func(100);	//错误！

	// 如果通过子类对象访问到父类中同名成员，需要加作用域
	s1.Base::func();
	s1.Base::func(100);

}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}