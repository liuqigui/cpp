/*
1.3类模板
1.3.1类模板语法
类模板作用:
·建立一个通用类，类中的成员数据类型可以不具体制定，用一个虚拟的类型来代表。

总结:类模扳和函数模板语法相似，在声明模板template后面加类，此类称为类模板
*/

#include<iostream>
#include<string>
using namespace std;

template<class NameType, class AgeType>
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
		cout << "姓名：" << m_Name << " 年龄：" << m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;

};

void test01()
{
	 
	Person<string, int> p1("孙悟空", 18);
	p1.showPerson();

}

int main()
{
	test01();

	system("pause");
	return 0;
}