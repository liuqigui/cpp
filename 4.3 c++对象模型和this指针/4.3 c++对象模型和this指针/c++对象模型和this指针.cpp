/*
4.3 C++对象模型和this指针
4.3.1成员变量和成员函数分开存储
在C++中,类内的或员变量和成员函教分开存储
只有非静态成员变量才属于类的对象上

4.3.2 this指针概念
通过4.3.1我们知道在C++中成员变星和成员函数是分开存储的
每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
那么问题是:这一块代码是如何区分那个对象调用自己的呢?、

C++通过提供特殊的对象指针, this指针，解决上述问题。
this指针指向被调用的成员函数所属的对象

this指针是隐含每一个非静态成员函数内的一种指针
this指针不需要定义，直接使用即可

this指针的用途:
·当形参和成员变是同名时，可用this指针来区分
·在类的非静态成员函数中返回对象本身，可使用return *this

4.3.3空指针访问成员函数
C++中空指针也是可以调用成员函数的，但是也要注急有没有用到this指针
如果用到this指针，需要加以判断保证代码的健壮性

4.3.4 const修饰成员函数
常函数:
·成员函数后加const后我们称为这个函数为常函数
·常函数内不可以修改或员属性
·成员属性声明时加关键字mutable后，在常函数中依然可以修改
常对象:
·声明对象前加const称该对象为常对象
·常对象只能调用常函数

*/

#include<iostream>

using namespace std;

//成员变量 和 成员函数 分开存储
class Person {
	int m_A;	//非静态成员变量	属于类的对象上

	static int m_B;		//静态成员变量	不属于类的对象上

	void func() {	//非静态成员函数	不属于类的对象上

	}

	static void func2() {	//静态成员函数	不属于类的对象上

	}
};

void test01() {
	Person p;
	//空对象占用内存空间为：1
	//c++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址
	cout << "size of p = " << sizeof(p) << endl;	//1
}

void test02() {
	Person p;
	cout << "size of p = " << sizeof(p) << endl;	//4 int

}

//4.3.2 this指针概念

class Person1 {
public:
	Person1(int age) {
		this->age = age;	//this指针指向被调用的成员函数所属的对象
	}

	Person1& PersonAddAge(Person1 &p) {
		this->age += p.age;

		//this指向p2的指针，而*this指向的就是p2这个对象本体
		return *this;
	}

	int age;
};

//1.解决名称冲突
void test03() {
	Person1 p(18);
	cout << p.age << endl;
}

//2.返回对象本身用*this
void test04() {
	Person1 p1(10);

	Person1 p2(10);

	p2.PersonAddAge(p1);
	//链式编程思想 cout << ...
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

	cout << "p1的年龄为：" << p1.age << endl;
	cout << "p2的年龄为：" << p2.age << endl;
}

//4.3.3空指针访问成员函数
//C++中空指针也是可以调用成员函数的，但是也要注急有没有用到this指针
//如果用到this指针，需要加以判断保证代码的健壮性
class Person2 {
public:
	void showClassName() {
		cout << "this is Person2 class" << endl;
	}

	void showPersonAge() {

		//this为NULL，系统会崩了，加一个if语句，增强代码健壮性
		if (this == NULL) {
			return;
		}

		//cout << "age = " << this->m_Age << endl;	//报错，传入的指针为空，默认！
		cout << "age = " << m_Age << endl;
	}

	int m_Age;
};

void test05() {
	Person2 *p = NULL;

	p->showClassName();	//没错！

	p->showPersonAge();
}

//4.3.4 const修饰成员函数
//常函数 :
//·成员函数后加const后我们称为这个函数为常函数
//·常函数内不可以修改或员属性
//·成员属性声明时加关键字mutable后，在常函数中依然可以修改
//常对象 :
//·声明对象前加const称该对象为常对象
//·常对象只能调用常函数
class Person3 {
public:
	//this指针本质是指针常量，指针的指向是不可以修改的
	//const Person3 * const this;
	void showPerson3() const{	//常函数	
		//this->m_A = 100;	//报错！
		m_B = 199;
		cout << "常函数" << endl;
	}

	void func() {
		cout << "函数" << endl;
		m_A = 199l;
	}

	int m_A;
	mutable int m_B;	//特殊变量，即使在常函数中，也可以修改这个值
};

void test06() {
	const Person3 p;	//在对象前加const，变为常对象
	//p.m_A = 100;	//报错！常对象也不可以修改
	p.m_B = 103;	//mutable修饰的m_B，常对象也可以修改

	//常对象只可以调用常函数
	p.showPerson3();
	//p.func();	//报错！ 不可以调用普通成员函数，因为普通成员函数可以修改属性。
}

int main() {
	cout << "4.3.1成员变量和成员函数分开存储" << endl;
	//test01();
	//test02();

	cout << "4.3.2 this指针概念" << endl;
	//test03();
	//test04();

	cout << "4.3.3空指针访问成员函数" << endl;
	//test05();

	cout << "4.3.4 const修饰成员函数" << endl;


	system("pause");
	return 0;
}