/*
1.2.6模板的局限性
局限性:
·模板的通用性并不是万能的



template<class T>
void f(T a, T b)
{
	a = b;
}
在上述代码中提供的赋值操作，如果传入的a和b是一个数组，就无法实现了

template<class T>
void fu(T a, T b)
{
	if (a > b) {
		...
	}
}
在上述代码中，如果T的数据类型传入的是像Person这样的自定义数据类型，也无法正常运行
因此C++为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模板


总结:
·利用具体化的模板，可以解决自定义类型的通用化
·学习模板并不是为了写模板，而是在STL能够运用系统提供的模板
*/

#include<iostream>
#include<string>

using namespace std;

template<class T>
bool myCampare(T &a, T &b)
{
	if (a == b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void test01()
{
	int a = 10;
	int b = 20;
	cout << myCampare(a, b) << endl;
}

class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	int age;
	string name;

};

template<> bool myCampare(Person &p1, Person &p2)
{
	if (p1.name == p2.name && (p1.age == p2.age)) {
		return 1;
	}
	else
	{
		return 0;
	}
}


void test02()
{
	Person p1("tom", 10);
	Person p2("tom", 10);

	//cout << myCampare(p1, p2) << endl;	//错误！
	//1.运算符重载 重载==
	
	//2.利用具体化的Person的版本来实现代码，优先调用
	cout << myCampare(p1, p2) << endl;

}

int main()
{
	cout << "模板的局限性:" << endl;
	//test01();
	test02();

	system("pause");
	return 0;
}