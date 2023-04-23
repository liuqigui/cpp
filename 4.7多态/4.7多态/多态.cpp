/*
4.7多态
4.7.1多态的基本概念
多态是C+面向对象三大特性之一多态分为两类
·静态多态:函数重载和运算符重载属于静态多态，复用函数名
·动态多态:派生类和虚函数实现运行时多态

静态多态和动态多态区别:
·静态多态的函数地址早绑定·编译阶段确定函教地址动态
·多态的函数地址晚绑定·运行阶段确定函数地址

下面通过案例进行讲解多态

总结：
多态满足条件
·有继承关系
·子类重写父类中的虚函数

多态使用条件
·父类指针或引用指向子类对象
重写:函数返回值类型函教名参数列表完全—致称为重写

*/

#include<iostream>

using namespace std;

class Animal
{
public:

	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat : public Animal
{
public:
	//重写 函数返回值的类型 函数名 参数列表 完全相同
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog : public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

//执行说话的函数
//地址早绑定，在编译阶段就确定函数的地址

//如果想执行让猫说话，那这个函数的地址就不能提前绑定，需要在运行阶段进行绑定，也就是晚绑定

//动态多态的满足条件
//1.有继承关系
//2.子类要重写父类的虚函数

//动态多态的使用
//父类的指针或者引用来 执行子类的对象

void doSpeak(Animal &animal)	//Animal & animal = cat;
{
	animal.speak();
}

void test01()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

void test02()
{
	cout << "sizeof Animal=" << sizeof(Animal) << endl;
}

int main()
{
	cout << "多态" << endl;
	//test01();
	test02();

	system("pause");
	return 0;
}