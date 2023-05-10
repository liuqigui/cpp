/*
1.3.7类模板分文件编写
学习目标:
·掌握类模板成员函数分文件编写产生的问题以及解决方式
问题
·类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

解决:
·解决方式1:直接包含.cpp源文件
·解决方式2∶将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制

总结:主流的解决方式是第二种，将类模板成员函数写到一起，并将后缀名改为.hpp

*/

#include<iostream>
#include<string>


//1.直接包含person文件
//#include"person.h"	//错误！
//#include"person.cpp"

//解决方式2∶将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制  类模板！、
#include"person.hpp"

using namespace std;

//template<class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//
//	void showPerson();
//
//	T1 m_Name;
//	T2 m_Age;
//};

//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template<class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "姓名：" << this->m_Name << " 年龄：" << this->m_Age << endl;
//}

void test01()
{
	Person<string, int> p1("tom", 23);
	p1.showPerson();
}

int main()
{
	test01();

	system("pause");
	return 0;
}