/*
1.3.3类模板中成员函数创建时机
类模板中成员函数和普通类中成员函数创建时机是有区别的:
普通类中的成员函数—开始就可以创建
类模板中的成员函数在调用时才创建

总结:类模板中的成员函数并不是一开始就创建的，在调用时才去创建
*/

#include<iostream>

using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "showPerson1()" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "showPerson2()" << endl;
	}
};

//类模板中的成员函数在调用时才创建
template<class T>
class Myclass
{
public:
	T obj;

	//类模板的成员函数
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}
};

void test01()
{
	Myclass<Person1>m;
	m.func1();
	//m.func2();	错误！

	Myclass<Person2>m1;
	//m1.func1(); 错误！
	m1.func2();	
}

int main()
{
	cout << "1.3.3类模板中成员函数创建时机" << endl;
	test01();

	system("pause");
	return 0;
}