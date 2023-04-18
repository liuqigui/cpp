/*
2引用
2.1 引用的基本语法：数据类型 &别名 = 原名

2.2 引用的注意事项：
1.引用必须要初始化
2.引用一旦初始化之后就不能更改了

2.3 引用做函数参数
作用：函数传参时，可以利用引用的技术让形参修饰实参
优点:可以简化指针修改实参，和地址传递效果一样，但是更简单

2.4 引用做函数返回值
作用:引用是可以作为函数的返回值存在的
注意:不要返回局部变量引用
用法:函数调用作为左值

2.5 引用的本质
本质：引用的本质在c++内部实现的是一个指针常亮

2.6 常量引用
作用:常量引用主要用来修饰形餐，防止误操作
在函数形参列表中，可以加const修饰形参，防止形参改变实参

*/

#include<iostream>

using namespace std;

//交换函数
//1.值传递
void swap01(int a, int b) {
	cout << "值传递" << endl;
	int temp = a;
	a = b;
	b = temp;

	cout << "sw01_a = " << a << endl;
	cout << "sw01_b = " << b << endl;
}

//2.地址传递
void swap02(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	cout << "sw02_a = " << *a << endl;
	cout << "sw02_b = " << *b << endl;
}
//引用传递
void swap03(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;

	cout << "sw03_a = " << a << endl;
	cout << "sw03_b = " << b << endl;
}

//不要返回局部变量引用
int& test01() {
	int a = 10;
	return a;
}

int& test02() {

	static int a = 10;	//静态变量，存放在全局区，有系统释放
	return a;
}

//发现是引用，转换为int* const ref = &a；
void func1(int &ref) {
	ref = 100;	//ref是引用
}

//打印数据输出
void showValue(const int& value) {
	//value = 1000;	//const加上之后，形参就不可以修改了，功能就和值传递一样了
	cout << "value =" << value << endl;
}

int main() {
/*	cout << "2.1 引用 引用的基本语法" << endl;
	int a = 10;
	int &b = a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	b = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	cout << "2.2 引用的注意事项" << endl;
	//int &c;	引用必须要初始化
	int c = 20;
	//&b = c;	引用一旦初始化之后就不能更改了
	b = c;	//赋值操作，而不是更改引用
	cout << a << b << c;	//都是20

	cout << "2.3 引用做函数参数" << endl;
	int d = 10;
	swap01(a, d);	//值传递，形参不会修饰实参
	swap02(&a, &d);	//地址传递，形参会修饰实参
	swap03(a, d);	//引用传递，形参会修饰实参


	cout << "a = " << a << endl;	//20
	cout << "d = " << d << endl;	//10

	cout << "2.4 引用做函数返回值" << endl;
	int &ref = test01();
	cout << "ref:" << ref << endl;	//第一次正确，编译器做了保留
	cout << "ref:" << ref << endl;	//第二次错误，a的内存已经释放

	int &ref2 = test02();
	cout << "ref2:" << ref2 << endl;
	cout << "ref2:" << ref2 << endl;

	test02() = 1000;	//给test02中的a赋值1000；
	cout << "ref2:" << ref2 << endl;
	cout << "ref2:" << ref2 << endl;

	cout << "2.5 引用的本质：" << endl;
	int a1 = 10;

	//自动转换为int* const ref = &a;指针常量是指针指向不可以更改，也说明为什么引用不可以更改
	int& ref = a;
	ref = 20;	//内部发现ref是引用，自动磅我们转换为：*ref = 20;

	cout << "a:" << a << endl;
	cout << "ref;" << ref << endl;

	func1(a);
//结论:C++推荐用引用技术，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了

	cout << "常量引用" << endl;
	int a2 = 10;
	//int & ref = 10;	//引用必须引用一块合法的区域
	const int & ref1 = 10;	//加上const之后，编译器将代码修改为int temp = 10; const int & ref = temp;
	//ref1 = 20;	//加入const之后就变为只读，不可以修改
*/
	int a3 = 100;
	showValue(a3);
	cout << "a3 = " << a3 << endl;


	system("pause");
	return 0;
}