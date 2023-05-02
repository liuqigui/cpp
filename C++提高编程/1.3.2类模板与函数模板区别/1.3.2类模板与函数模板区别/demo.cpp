/*
1.3.2类模板与函数模板区别

类模板与函数模板区别主要有两点:
1.类模板没有自动类型推导的使用方式
2.类模板在模板参数列表中可以有默认参数

*/

#include<iostream>

using namespace std;

//类模板和函数模板区别
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
		cout << "name;" << m_Name << " age:" << m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;

};

int main()
{

	system("pause");
	return 0;
}