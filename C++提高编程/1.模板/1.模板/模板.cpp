/*
·本阶段主要针对C++泛型编程和ST支术做详细讲解，探讨C++更深层的使用
1模板
1.1模板的概念
模板就是建立通用的校具,大大提高复用性

模板的特点:
模板不可以直接使用。它只是一个框架
模板的通用并不是万能的

1.2函数模板
·C++另一种编程思想称为泛型编程,主要利用的技术就是模板.
·C++提供两种模板机制:函数模板和类模板
1.2.1函数模板语法
函数模板作用:
建立一个通用函效，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表。

语法：
template<typename T>
函数声明或定义

解释：
template ... 声明创建模板
typename ... 表面其后面的符号是一种数据类型，可以用class代替
T ... 通用的数据类型，名称可以替换，通常为大写字母

总结:
·函数模板利用关键字template
·使用函数模板有两种方式:自动类型推导、显示指定类型
·模板的目的是为了提高复用性,将类型参数

1.2.2函数模板注意事项
注意事项:
·自动类型推导，必须推导出一致的数据类型T,才可以使用
·模板必须要确定出T的数据类型，才可以使用


1.2.3函数模板案例案例描述:
·利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
·排序规则从大到小,排序算法为选择排序
·分别利用char数组和int数组进行测试

1.2.4普通函数与函数模板的区别
普通函数与函数模板区别;
·普通函教调用时可以发生自动类型转换〔隐式类型转换)
·函数模板调用时，如果利用自动类型推导,不会发生隐式类型转换
·如果利用显示指定类型的方式，可以发生隐式类型转换

1.2.5普通函数与函数模板的调用规则
调用规则如下:
1.如果函数模板和普通函数都可以实现，优先调用普通函数
2.可以通过空模板参数列表来强制调用函数模板
3.函数模板也可以发生重载
4.如果函数模板可以产生更好的匹配,优先调用函数模板

总结:既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性\

1.2.6模板的局限性
局限性:
·模板的通用性并不是万能的
*/

#include<iostream>

using namespace std;

//函数模板

//两个整型交换函数
void swapInt(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void swapDouble(double &a, double &b) {
	double temp = a;
	a = b;
	b = temp;
}

template<typename T>	//声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 10;
	int b = 20;
	//swapInt(a, b); 利用函数模板进行交换
	//两种方式来使用函数模板
	//1.自动类型推导 
	//mySwap(a, b);

	//2.显示指定类型
	mySwap<int>(a, b);

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	double c = 1.1;
	double d = 2.2;
	swapDouble(c, d);
	cout << "c = " << c << endl;
	cout << "c = " << c << endl;

}

template<class T>
void  func()
{
	cout << "func调用！" << endl;
}

void test02()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	//mySwap(a, c);		错误 推导不出一致的T类型

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	//func();	//错误，没有与参数列表匹配的函数模板"func”实例
	func<int>();	//模板必须要确定出T的数据类型，才可以使用

}

//1.2.3函数模板案例案例描述:
//·利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
//·排序规则从大到小, 排序算法为选择排序
//·分别利用char数组和int数组进行测试
template<class T>
void selectSort(T arr[], int len)
{
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i + 1; j < len; j++) 
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			T temp = arr[max];
			arr[max] = arr[i];
			arr[i] = temp;
		}
	}
}

template<class T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}

void test03()
{
	//测试char数组
	char charArr[] = "acbdelkf";
	int num = sizeof(charArr) / sizeof(charArr[0]);
	selectSort(charArr, num);
	printArray(charArr, num);

	int intArr[] = { 1, 4,5,8,3,4,645,76 };
	int num1 = sizeof(intArr) / sizeof(intArr[0]);
	selectSort(intArr, num1);
	printArray(intArr, num1);

}

//1.2.4普通函数与函数模板的区别
//普通函数与函数模板区别;
//·普通函教调用时可以发生自动类型转换〔隐式类型转换)
//·函数模板调用时，如果利用自动类型推导, 不会发生隐式类型转换
//·如果利用显示指定类型的方式，可以发生隐式类型转换
int myAdd01(int a, int b)
{
	return a + b;
}

template<class T>
int myAdd02(T a, T b)
{
	return a + b;
}


void test04()
{
	int a = 10;
	int b = 20;
	char c = 'c';	//

	cout << myAdd01(a, b) << endl;
	cout << myAdd01(a, c) << endl;	//普通函教调用时可以发生自动类型转换〔隐式类型转换)

	//cout << myAdd02(a, c) << endl;	//报错！自动类型推导不可以发生隐式类型转换
	cout << myAdd02<int>(a, c) << endl;	//利用显示指定类型的方式，可以发生隐式类型转换

}

//1.2.5普通函数与函数模板的调用规则
//调用规则如下 :
//1.如果函数模板和普通函数都可以实现，优先调用普通函数
//2.可以通过空模板参数列表来强制调用函数模板
//3.函数模板也可以发生重载
//4.如果函数模板可以产生更好的匹配, 优先调用函数模板

void myPrint(int a, int b)
{
	cout << "调用普通函数！" << endl;
}

template<class T>
void myPrint(T a, T b)
{
	cout << "调用模板函数！" << endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
	cout << "调用模板重载函数！" << endl;
}

void test05()
{
	int a = 10;
	int b = 20;
	myPrint(a, b);		//1.如果函数模板和普通函数都可以实现，优先调用普通函数

	myPrint<>(a, b);	//2.可以通过空模板参数列表来强制调用函数模板

	myPrint(a, b, 100);	//3.函数模板也可以发生重载

	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);	//4.如果函数模板可以产生更好的匹配, 优先调用函数模板

}

int main()
{
	cout << "模板函数语法：" << endl;
	//test01();
	//test02();
	//test03();
	//test04();
	test05();


	system("pause");
	return 0;
}