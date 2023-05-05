/*
1.3.2类模板与函数模板区别

类模板与函数模板区别主要有两点:
1.类模板没有自动类型推导的使用方式
2.类模板在模板参数列表中可以有默认参数


总结:
·类模板使用只能用显示指定类型方式
·类模板中的模板参数列表可以有默认参数
*/

#include<iostream>
#include<string>

using namespace std;

//类模板和函数模板区别
template<class NameType, class AgeType=int>//默认AgeType为int
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name;" << m_Name << " age:" << m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;

};

//1.类模板没有自动类型推导的使用方式
void test01()
{
	//Person p("孙悟空", 100); 错误！无法用自动类型推导
	Person<string, int>p("孙悟空", 1000);
	p.showPerson();


}

//2.类模板在模板参数列表中可以有默认参数
void test02()
{
	Person<string>p1("猪八戒", 999);
	p1.showPerson();
}

int main()
{
	cout << "类模板与函数模板区别" << endl;
	test01();
	test02();

	system("pause");
	return 0;
}