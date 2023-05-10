/*
1.3.8类模板与友元

学习目标:
掌握类模板配合友元函数的类内和类外实现
全局函数类内实现-直接在类内声明友元即可
全局函数类外实现–需要提前让编译器知道全局函数的存在

总结:建议全局函数做类内实现，用法简单，而且编译器可以直接识别
*/

#include<iostream>
#include<string>

using namespace std;

template<class T1, class T2>
class Person;

//类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2> p) {
	cout << "类外实现--姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;

}

template<class T1, class T2>
class Person
{
	//全局函数 类内实现
	friend void printPerson1(Person<T1, T2> p) {
		cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
	}

	//全局函数 类内实现
	//加一个空模板的函数列表
	//如果全局函数 是类外实现，需要让编译器提前知道这个函数的存在
	friend void printPerson2<>(Person<T1, T2> p);

public:
	Person(T1 name, T2 age) {
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};




//1.全局函数在类内实现
void test01() {
	Person<string, int>p("tom", 12);

	printPerson1(p);
}

void test02() {
	Person<string, int>p("jerry", 21);

	printPerson2(p);
}


int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}