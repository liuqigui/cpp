/*
面向对象

1.内存分区模型
·代码区：存放函数体的二进制代码，由操作系统进行管理
·全局区：存放全局变量和静态变量以及常量
·栈区：由编译器自动分配释放,存放函数的参数值,局部变量等
·堆区：由程序员分配和释放,若程字员不释放,程序结束时由操作系统回收
意义：不同区域存放的数据，赋予不同的生命周期,给我们更大的灵活编程

1.1 程序运行之前
在程序编译后，生成了exe可执行程就未执行该程序前分为两个区域
代码区:
	存放CPU执行的机器指令
	代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
	代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令

全局区:
	全局变星和静态变量存放在此.
	全局区还包含了常量区,字符串常量和其他常量也存放在此
	该区域的数据在程序结束后由操作系统释放

1.2 程序运行之后
栈区：
	由编译器自动分配释放,存放函数的参教值,局部变量等
	注意事项:不要返回局部变量的地址，栈区开辟的数据由编译器自动释放

堆区：
	由程序员分配释放蘑程序员不释放,程序结束时由操作系统回收
	在C++中主要利用new在堆区开辟内存

1.3 new操作符
C++中利用new操作符在堆区开辟数据
堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
语法:new数据类型
利用new创建的教据，会返回该数据对应的类型的指针
*/

#include<iostream>

using namespace std;

//创建普通全局变量
int g_a = 10;
int g_b = 10;

//创建const修饰的全局变量
const int c_g_a = 10;
const int c_g_b = 10;

int* func(int b) { //形参也会存放在栈区
	b = 100;
	int a = 10;	//局部变量	存放在栈区，栈区的数据在函数执行后自动释放
	return &a;
}

int* func1() {
	int a = 10;	//局部变量	存放在栈区，栈区的数据在函数执行后自动释放
	int * p = new int(10);	//利用new关键字，可以开辟数据到堆区
	
	return p;
	//return &a;
}

//1、new的基本语法
int * func2() {
	//在堆区创建整形数据
	//new返回的是该数据类型的指针
	int * p = new int(10);
	return p;
}

void test01() {
	int * p = func2();
	cout << *p << endl;
	cout << *p << endl;

	delete p;	//delete释放new出来的内存
	//cout << *p << endl;	//内存已经释放，再次访问就是非法报错

}

//2、在堆区利用new开辟数组
void test02() {
	cout << "//2、在堆区利用new开辟数组" << endl;
	//创建10个整形数据的数组，在堆区
	int * arr = new int[10];

	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;	//给10个元素赋值，100-109
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;	//打印输出操作
	}
	delete[] arr;	//释放数组的时候，需要加[]才可以
}


int main() {

	//全局区

	//全局变量、静态变量、常量

	//创建普通局部变量
	int a = 10;
	int b = 10;
	//局部变量地址
	cout << "a的地址：" << (int)&a << endl;
	cout << "b的地址：" << (int)&b << endl;

	//全局变量
	cout << "g_a的地址：" << (int)&g_a << endl;
	cout << "g_b的地址：" << (int)&g_b << endl;

	//创建静态变量
	static int s_a = 10;
	static int s_b = 10;

	//静态变量地址
	cout << "s_a的地址：" << (int)&s_a << endl;
	cout << "s_b的地址：" << (int)&s_b << endl;

	//常量
	//字符串常量
	cout << "字符串地址：" << (int)&"HelloWrold" << endl;

	//const修饰的变量
	//const修饰的全局变量、const修饰的局部变量
	cout << "c_g_a的地址：" << (int)&c_g_a << endl;
	cout << "c_g_b的地址：" << (int)&c_g_b << endl;

	//创建const修饰的局部变量
	const int c_l_a = 10;
	const int c_l_b = 10;

	//const修饰的局部变量的地址
	cout << "c_l_a的地址：" << (int)&c_l_a << endl;
	cout << "c_l_b的地址：" << (int)&c_l_b << endl;


	//栈区注意事项
	//栈区的数据由编译器管理开辟和释放
	//接受func函数的返回值
	cout << "栈区注意事项" << endl;

	int * p = func(1);
	cout << *p << endl;	//10，编辑器保留一次
	cout << *p << endl;	//乱码，第二次编辑器就不保留了

	//在堆区开辟数据
	cout << "//在堆区开辟数据" << endl;
	int * p1 = func1();
	cout << *p1 << endl;	//两次都是10，存放在堆区编辑器不会自动删除
	cout << *p1 << endl;	//堆区地址存放到了栈区，可以直接指过来

	//1.3 new使用
	cout << "//1.3 new使用" << endl;
	test01();
	test02();

	system("pause");
	return 0;
}