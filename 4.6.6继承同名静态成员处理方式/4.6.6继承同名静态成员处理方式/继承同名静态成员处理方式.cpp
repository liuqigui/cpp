/*
4.6.6继承同名静态成员处理方式
问题:继承中同名的静态成员在子类对象上如何进行访问?
静态成员和非静态成员出现同名。处理方式一致
·访问子类同名成员直接访问即可
·访问父类同名成员需要加作用域

总结:同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式(通过对象和通过类名)
*/

#include<iostream>

using namespace std;

//继承同名静态成员处理方式
class Base
{
public:
	static int m_A;

	static void func()
	{
		cout << "Base->func()" << endl;

	}

	static void func(int a)
	{
		cout << "Son->func(int a)" << endl;
	}

};

int Base::m_A = 100;


class Son :public Base
{
public:
	static int m_A;

	static void func()
	{
		cout << "Son->func()" << endl;

	}

	
};

int Son::m_A = 1200;

void test01()
{
	//1、通过对象来访问
	cout << "通过对象来访问" << endl;
	Son s;
	cout << "Son->m_A = " << s.m_A << endl;
	cout << "Base->m_A = " << s.Base::m_A << endl;

	//2、通过类名来访问
	cout << "通过类名来访问" << endl;
	cout << "Son->m_A = " << Son::m_A << endl;

	// 第一个::代表通过类名方式访问第二个::代表访问父类作用域下
	cout << "Base->m_A = " << Son::Base::m_A << endl;

}

void test02()
{
	//1、通过对象来访问
	cout << "通过对象来访问" << endl;
	Son s1;
	s1.func();
	s1.Base::func();

	//2、通过类名来访问
	cout << "通过类名来访问" << endl;
	Son::func();
	// 第一个::代表通过类名方式访问第二个::代表访问父类作用域下
	Son::Base::func();

	//子类出现和父类同名静态成员函数，也会隐藏父类中所有同名成员函数
	//如果想访问父类中被隐藏同名成员，需要加作用域
	//Son::func(100);
	Son::Base::func(100);

}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}