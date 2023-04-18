/*
3 函数提高
3.1 函数默认参数
	在C++中，函数的形参列表中的形参是可以有默认值的。
	语法:返回值类型 函数名(参数 = 默认值){}

3.2 函数占位参数
	C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
	语法:返回值类型函数名(数据类型){}
	在现阶段函数的占位参数存在意义不大，但是后面的课程中会用到该技术

3.3 函数重载
3.3.1函数重载概述
	作用:函数名可以相同,提高复用性
	函数重载满足条件:
	·同一个作用域下·函数名称相同
	·函数参数类型不同或者个数不同或者顺序不同
	注意:函数的返回值不可以作为函数重载的条件
3.3.2 函数重载的注意事项
	·引用作为重载条件
	·函故重载碰到函数默认参数

*/

#include<iostream>

using namespace std;


//函数默认参数
//语法： 返回值类型 函数名(参数 = 默认值){}
int func(int a, int b = 30, int c = 20) {
	return a + b + c;
}

//注意事项
//1、如果某个位置有个默认参数，那么从这个位置往后往后从左到右都必须有默认值
//int func2(int a, int b=10, int c) {	//报错了！
//int func2(int a, int b=10, int c=20) {	//这才对！
//	return a + b + c;
//}
//2、如果函数声明有默认参数，那么函数实现就不能有默认参数了
int func2(int a = 10, int b = 14);	//函数的声明
//int func2(int a = 20, int b = 15) {		//报错了！
int func2(int a, int b) {		//这才对！声明和实现只能有一个有默认参数
	return a + b;
}


//占位参数  在现阶段函数的占位参数存在意义不大，但是后面的课程中会用到该技术
void func3(int a, int=19) {	//第二个int属于占位参数
	cout << "this is func" << endl;
}

//函数重载	可以让函数名相同，提高复用性
//函数重载的满足条件
//1、同一个作用域
//2、函数名称相同
//3、函数参数类型不同、个数不同或顺序不同
void func1() {
	cout << "func1的调用" << endl;
}

void func1(int a) {
	cout << "func1_1的调用" << endl;
}

//函数的返回值不可以作为函数重载的条件
//int func1(int a) {
//	cout << "int返回值的func1函数" << endl;
//}

//函数重载的注意事项
//1.引用作为重载的条件
void func4(int &a) {	//int & a = 10;不合法！
	cout << "func4(int &a)的调用" << endl;
}

void func4(const int &a) {	
	cout << "func4(const int &a)的调用" << endl;
}


//2、函数重载遇到默认参数
void func5(int a, int b = 10) {
	cout << "func5(int a, int b)的调用" << endl;

}

void func5(int a) {
	cout << "func5(int a)的调用" << endl;

}


int main() {

	cout << "函数默认参数" << endl;
	cout << func(20, 10, 30) << endl;
	cout << func(20) << endl;
	cout << func(20, 20) << endl;

	cout << "注意事项" << endl;
	cout << func2(20, 20) << endl;
	
	cout << "占位参数" << endl;
	func3(10, 20);
	func3(10);

	cout << "函数重载" << endl;
	func1();	//void func1()
	func1(10);	//void func1(int a)

	cout << "函数重载的注意事项" << endl;
	int a = 10;
	func4(a);	//void func4(int &a)  无const
	func4(10);	//void func4(const int &a)	有const

	//func5(10);	//当函数重载遇到默认参数，出现二义性，报错！尽量避免这种情况


	system("pause");
	return 0;
}