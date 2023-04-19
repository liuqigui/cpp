/*
4.2对象的初始化和清理
·生活中我们买的电子产品都基本会有出厂设置，在某一天我们不用时候也会删除一些自己信息数据保证安全。
·C++中的面向对象来源于生活，每个对象也都会有初始设置以及对象销毁前的清理数据的设置。

4.2.1构造函数和析构函数
对象的初始化和清理也是两个非常重要的安全问题
	一个对象或者变量没有初始状态，对其使用后果是未知
	同样的使用完一个对象或变量,没有及时清理，也会造成一定的安全问题
C++利用了构造函数和析构函数解决上述问题，这两个函数将会被编译器自动调用，完成对象初始化和清理工作。对象的初始化和清理工作是编译器强制要我们做的事情，因此如果我们不提供构造和析构，编译器会提供编译器提供的构造函数和析构函数是空实现。
·构造函数:主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用。
·析构函数:主要作用在于对象销毁前系统自动调用，执行一些清理工作。

构造函数语法:类名(){}
1.构造函数，没有返回值也不写void
2.函数名称与类名相同
3.构造函数可以有参数，因此可以发生重载
4.程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次

析构函数语法:~类名(){}
1.析构函数，没有返回值也不写void
2.函数名称与类名相同,在名称前加上符号~
3.析构函数不可以有参数，因此不可以发生重载
4.程席在对象铛铅前会白动调用析构．无须羊动调用.而月只会调用—次


4.2.2构造函数的分类及调用
两种分类方式:
	按参数分为:有参构造和无参构造
	按类型分为:普通构造和拷贝构造
三种调用方式:
	括号法
	显示法
	隐式转换法

4.2.3拷贝构造函数调用时机
C++中拷贝构造函数调用时机通常有三种情况
	·使用一个已经创建完毕的对象来初始化一个新对象
	·值传递的方式给函数参数传值
	·以值方式返回局部对象

4.2.4构造函数调用规则
默认情况下，C++编译器至少给一个类添加3个函数
1．默认构造函数(无参，函数体为空)
2．默认析构函数(无参，函数体为空)
3．默认拷贝构造函敦，对属性进行值拷贝

构造函数调用规则如下:
·如果用户定义有参构造函数，C++不在提供默认无参构造，但是会提供默认拷贝构造
·如果用户定义拷贝构造函数，C++不会再提供其他构造函教

4.2.5深拷贝与浅拷贝
深浅拷贝是面试经典问题,也是常见的一个坑
浅拷贝:简单的赋值拷贝操作
深拷贝:在堆区重新申请空间,进行拷贝操作
总结:如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，时止浅拷贝带来的问题

4.2.6初始化列表
作用:
C++提供了初始化列表语法，用来初始化属性
语法:构造函数():厦性1(值1) ,属性2(值2)..{}

4.2.7类对象作为类成员
C++类中的或员可以是另—个类的对象，我们称该成员为对象成员

4.2.8静态成员
静态成员就是在成员变是和成员函数前加上关键字static，称为静态成员
静态成员分为:
·静态成员变量
	·所有对象共享同一份数据
	·在编译阶段分配内存
	·类内声明，类外初始化
·静态成员函教
	·所有对象共享同一个函数
	·静态成员函数只能访问静态成员变量

*/

#include<iostream>
#include<string>

using namespace std;

class Person
{

	
public:
	//1.构造函数，没有返回值也不写void
	//2.函数名称与类名相同
	//3.构造函数可以有参数，因此可以发生重载
	//4.程序在调用对象时候会自动调用构造，无须手动调用, 而且只会调用一次
	Person() {
		cout << "Person构造函数的调用" << endl;
	}

	//1.析构函数，没有返回值也不写void
	//2.函数名称与类名相同, 在名称前加上符号~
	//3.析构函数不可以有参数，因此不可以发生重载
	//4.程席在对象铛铅前会白动调用析构．无须羊动调用.而月只会调用—次
	~Person(){
		cout << "Person的析构函数的调用" << endl;
	}

private:

};

//构造和析构都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
void test01() {
	Person p;	//在栈上的数据，test01调用之后会自动释放
}

class Person1
{
public:
	//按参数分为 : 有参构造和无参构造
	Person1() {
		cout << "Person构造函数的调用" << endl;
	}
	Person1(int a) {
		cout << "Person有参构造函数的调用" << endl;
		age = a;
	}

	//按类型分为:普通构造和拷贝构造
	Person1(const Person1 &p2) {
		age = p2.age;
		cout << "Person拷贝构造函数的调用" << endl;
	}

	~Person1() {
		cout << "Person的析构函数的调用" << endl;
	}
	int age;

private:
	//int age;
};

//4.2.2构造函数的分类及调用
void test02() {
	//括号法
	cout << "括号法" << endl;
	Person1 p1;	//默认构造函数的调用
	Person1 p2(10);	//默认有参构造函数的调用
	Person1 p3(p2);	//拷贝构造

	//注意事项1
	//调用默认构造函数的时候不要用()
	//Person1 p1()	错误！编译器会任务这是函数的声明！

	cout << "p2的age：" << p2.age << endl; 
	cout << "p3的age：" << p3.age << endl;

	//显示法
	cout << "显示法" << endl;
	Person1 p4;
	Person1 p5 = Person1(10);
	Person1 p6 = Person1(p5);

	//Person1(10);	//匿名对象 特点：当前执行结束之后，系统会立即回收匿名对象
	//cout << "aaaaaaaaaa" << endl;

	//注意事项2
	//不要利用拷贝构造对象 初始化匿名对象
	//Person1(p6);	//编译器会认为这是Person1（p6）== Person1 p6；对象的声明

	//隐式转换法
	cout << "隐式转换法" << endl;
	Person1 p7 = 10;	//Person1 p7 = Person1(10);	有参构造
	Person1 p8 = p7;	//Person1 p7 = Person1(p7); 拷贝构造
}

//4.2.3拷贝构造函数调用时机
//C++中拷贝构造函数调用时机通常有三种情况
//·使用一个已经创建完毕的对象来初始化一个新对象
//·值传递的方式给函数参数传值
//·以值方式返回局部对象

class Person3
{
public:
	int m_Age;

	Person3() {
		cout << "Person默认构造函数的调用" << endl;
	}

	Person3(int age) {
		m_Age = age;
		cout << "Person有参构造函数的调用" << endl;
	}

	Person3(const Person3 &p) {
		m_Age = p.m_Age;
		cout << "Person拷贝构造函数的调用" << endl;
	}

	~Person3() {
		cout << "Person的析构函数的调用" << endl;

	}

private:

};

void test03() {
	Person3 p1(20);
	Person3 p2(p1);
	cout << "p1.m_Age:" << p1.m_Age << endl;
	cout << "p2.m_Age:" << p2.m_Age << endl;

}

//·使用一个已经创建完毕的对象来初始化一个新对象
//·值传递的方式给函数参数传值
void doWork(Person3 p) {
	p.m_Age = 100;
	cout << "p.m_Age:" << p.m_Age << endl;

}

//·以值方式返回局部对象
Person3 doWork2() {

	Person3 p1;
	cout << (int*)&p1 << endl;
	return p1;
}

void test04() {
	//Person3 p;
	//Person3 p1(20);
	//cout << "p1.m_Age:" << p1.m_Age << endl;

	//doWork(p);
	Person3 p2 = doWork2();
	cout << (int*)&p2 << endl;
}

//4.2.4构造函数调用规则
//默认情况下，C++编译器至少给一个类添加3个函数
//1．默认构造函数(无参，函数体为空)
//2．默认析构函数(无参，函数体为空)
//3．默认拷贝构造函敦，对属性进行值拷贝
//
//构造函数调用规则如下 :
//·如果用户定义有参构造函数，C++不在提供默认无参构造，但是会提供默认拷贝构造
//·如果用户定义拷贝构造函数，C++不会再提供其他构造函教
class Person4{
public:
	/*Person4() {
		cout << "Person默认构造函数的调用" << endl;
	}*/

	//Person4(int a) {
	//	m_Age = a;
	//	cout << "Person有参构造函数的调用" << endl;
	//}

	Person4(const Person4 & p) {
		cout << "Person拷贝构造函数的调用" << endl;
		m_Age = p.m_Age;
	}

	~Person4()
	{
		cout << "Person的析构函数的调用" << endl;
	}

	int m_Age;
};

//void test05() {
//	Person4 p;
//	p.m_Age = 18;
//	cout << "p的年龄为：" << p.m_Age << endl;
//
//
//	Person4 p2(p);
//
//	cout << "p2的年龄为：" << p2.m_Age << endl;
//
//}

void test06() {
	//Person4 p;		//如果用户定义有参构造函数，C++不在提供默认无参构造，但是会提供默认拷贝构造
	//Person4 p(29);
	Person4 p1();	//如果用户定义拷贝构造函数，C++不会再提供其他构造函教

}

//4.2.5深拷贝与浅拷贝
//深浅拷贝是面试经典问题, 也是常见的一个坑
//浅拷贝 : 简单的赋值拷贝操作
//深拷贝 : 在堆区重新申请空间, 进行拷贝操作
class Person5 {
public:
	int m_Age;
	int *m_Height;	//在堆区创建一个变量，先进后出

	Person5() {
		cout << "Person默认构造函数的调用" << endl;
	}

	Person5(int age, int height) {
		m_Age = age;
		m_Height = new int(height);
		cout << "Person有参构造函数的调用" << endl;
	}

	//自己实现一个拷贝构造函数 解决浅拷贝带来的问题
	Person5(const Person5 &p) {
		cout << "Person5拷贝构造函数的调用" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;	编辑器默认实现的就是这行代码
		//深拷贝
		m_Height = new int(*p.m_Height);	//对于堆内的数据，重新生成一个堆中内存数据

	}

	~Person5() {
		//析构代码，将堆区开辟数据做释放操作
		if (m_Height != NULL) {
			delete m_Height;
			m_Height = NULL;
		}	//堆区内容重复释放
		cout << "Person的析构函数的调用" << endl;

	}

};

void test07() {
	Person5 p1(18, 160);
	cout << "p1的年龄为：" << p1.m_Age << endl;
	cout << "p1的身高为：" << *p1.m_Height << endl;


	Person5 p2(p1);	//浅拷贝操作 
	cout << "p2的年龄为：" << p2.m_Age << endl;
	cout << "p2的身高为：" << *p2.m_Height << endl;	//堆区内容重复释放

}

//4.2.6初始化列表
//作用 :
//C++提供了初始化列表语法，用来初始化属性
//语法 : 构造函数() : 厦性1(值1), 属性2(值2)...{}
class Person6 {
public:
	////传统初始化操作
	//Person6(int a, int b, int c) {
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//初始化列表赋初值
	Person6(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {

	}


	int m_A;
	int m_B;
	int m_C;
};

void test08() {
	//Person6 p(10, 20, 30);

	Person6 p(30, 20, 10);
	cout << p.m_A <<  p.m_B << p.m_C << endl;
}

//4.2.7类对象作为类成员
//C++类中的或员可以是另—个类的对象，我们称该成员为对象成员

//手机的类
class Phone {
public:
	Phone(string pName) {
		m_Phone = pName;
		cout << "Phone的构造函数调用" << endl;

	}
	~Phone()
	{
		cout << "Phone的析构函数调用" << endl;
	}

	string m_Phone;
};

class PersonA {
public:
	PersonA(string name, string pName) :m_Name(name), m_Phone(pName){	//Phone m_Phone = pName	隐式转换法
		cout << "PersonA的构造函数调用" << endl;
	}

	~PersonA()
	{
		cout << "PersonA的析构函数调用" << endl;

	}

	//name
	string m_Name;

	//phone
	Phone m_Phone;
};

//当其他类对象左右本类成员，构造时候先构造类对象，再构造自身；析构的函数相反
void test09() {
	PersonA p("张达", "苹果15");
	cout << p.m_Name << "拿着" << p.m_Phone.m_Phone << endl;
}

//4.2.8静态成员
//静态成员就是在成员变是和成员函数前加上关键字static，称为静态成员
//静态成员分为 :
//·静态成员变量--类内声明，类外初始化
//	·所有对象共享同一份数据
//	·在编译阶段分配内存
//	·类内声明，类外初始化
//·静态成员函教
//	·所有对象共享同一个函数
//	·静态成员函数只能访问静态成员变量

//静态成员变量
class Person8 {
public:
	//1 所有对象共享同一份数据
	//2 在编译阶段分配内存
	//3 类内声明，类外初始化
	static int m_A;

	//静态成员变量也是有访问权限的
private:
	static int m_B;
};

int Person8::m_A = 100;
int Person8::m_B = 101;

void test10() {
	Person8 p;
	cout << p.m_A << endl;

	Person8 p2;
	p2.m_A = 200;
	cout << p.m_A << endl;
}

void test11() {
	//静态成员变量 不属于某个对象，所有对象共享同一份数据
	//因此静态成员变量有两种访问方式

	//1、通过对象访问
	Person8 p;
	cout << p.m_A << endl;

	//2、通过类名进行访问
	cout << Person8::m_A << endl;

	//cout << Person8::m_B << endl;	私有静态变量权限，类外不可以访问
}

//静态成员函教
//	·所有对象共享同一个函数
//	·静态成员函数只能访问静态成员变量
class Person9 {
public:
	static void func() {
		cout << "static void func" << endl;
		m_A = 104;	//静态成员函数可以访问静态成员变量
		//m_B = 14;	//报错！静态成员函数不可以访问非静态成员变量，无法区分到底是那个对象的m_B属性
	}

	static int m_A;
	int m_B;

	//静态成员函数也是有访问权限
private:
	static void func2() {
		cout << "static void func2" << endl;
	}
};

int Person9::m_A = 100;

//两种访问方式
void test12() {
	//1.通过对象访问
	Person9 p;
	p.func();

	//2.通过类名访问
	Person9::func();
	//Person9::func2();	类外访问不到私有静态成员函数
}

int main() {
	cout << "4.2.1构造函数和析构函数" << endl;
	//test01();
	//Person p1;

	cout << "4.2.2构造函数的分类及调用" << endl;
	//test02();

	cout << "4.2.3拷贝构造函数调用时机" << endl;
	//test03();
	//test04();

	cout << "4.2.4构造函数调用规则" << endl;
	//test05();
	//test06();

	cout << "4.2.5深拷贝与浅拷贝" << endl;
	//test07();

	cout << "4.2.6初始化列表" << endl;
	//test08();

	cout << "4.2.7类对象作为类成员" << endl;
	//test09();

	cout << "4.2.8静态成员" << endl;
	//test10();
	//test11();
	test12();

	system("pause");
	return 0;
}