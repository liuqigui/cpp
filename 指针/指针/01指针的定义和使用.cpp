/*
1.定义一个指针
2、使用指针

指针所用的内存空间

空指针

野指针


*/
#include<iostream>
using namespace std;

int main() {
	int a = 10;
	int * p;
	p = &a;
	cout << &a << endl;
	cout << p << endl;

	cout << *p << endl;

	int * p = NULL;
	cout << *p << endl;

	return 0;
}