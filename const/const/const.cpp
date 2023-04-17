/*
const修饰指针--常量指针
特点：指针的指向可以修改，指针指向的值不可以修改

const修饰p--指针常量
特点：指针的指向不可以修改，指针指向的值可以修改

const修饰指针和修饰p
特点：指针的指向不可以修改，指针指向的值不可以修改


指针和数组

指针和函数

指针、数组和排序
*/


#include<iostream>
using namespace std;

void swap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	cout << "swap01 " << a << " " << b << endl;

}

void swap02(int *pp1, int *pp2) {
	int temp = *pp1;
	*pp1 = *pp2;
	*pp2 = temp;
	cout << "swap02 " << *pp1 << " " << *pp2 << endl;

}

void bubbleSort(int *arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}

void printCout(int * arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << *(arr + i) << endl;
	}
}

int main() {
/*	int a = 10;
	int b = 10;
	int c = 20;
	const int * p = &a;	//常量指针
//	*p = 20;	错误！
	p = &b;
	cout << p << " " << *p << endl;

	int * const p1 = &a;
	*p1 = 100;
	cout << p1 << " " << *p1 << endl;

	const int * const p2 = &a;
	cout << p2 << " " << *p2 << endl;

	//指针和数组
	int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	cout << arr[0] << endl;
	int * p3 = arr;
	cout << *p3 << endl;
	p3++;
	cout << *p3 << arr[1] << *(p3+1) << "and" << *p3+1 << endl;
	cout << *(p3 + 1) << "and" << *p3 + 1 << endl;
	 
	for (int i = 0; i < 10; i++) {
		cout << *p3 << endl;
		p3++;
	}

	//指针和函数
	//1.值传递
	swap01(a, c);
	cout << a << " " << c << endl;

	//2.地址传递
	swap02(&a, &c);
	cout << a << " " << c << endl; */

	//指针、数组和函数
	//1.创建数组
	int arr[10] = { 4, 3, 6, 9, 1, 2, 10, 8 ,5, 7 };
	
	//2.创建函数，实现冒泡排序
	int len = sizeof(arr) / sizeof(arr[0]);

	//3.打印排序后的数组
	bubbleSort(arr, len);
	printCout(arr, len);

	return 0;
}