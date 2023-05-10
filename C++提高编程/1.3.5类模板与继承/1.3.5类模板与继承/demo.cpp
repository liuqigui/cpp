/*
1.3.5类模板与继承
当类模板碰到继承时，需要注意一下几点:
·当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
·如果不指定，编译器无法给子类分配内存
·如果想灵活指定出父类中T的类型，子类也需变为类模板

总结:如果父类是类模板，子类需要指定出父类中T的数据类型
*/

#include<iostream>

using namespace std;

template<class T>
class Base
{
	T m;
};

//class Son :public Base	//报错！少一个参数列表,算不出继承空间的东西
class Son :public Base<int>
{

};

void test01()
{
	Son s1;

}

//如果想灵活指定出父类中T的类型，子类也需变为类模板
template<class T1, class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1的数据类型：" << typeid(T1).name() << endl;
		cout << "T2的数据类型：" << typeid(T2).name() << endl;

	}

	T1 obj;
};

void test02()
{
	Son2<int, char>s2;

}

int main()
{
	test02();

	system("pause");
	return 0;
}