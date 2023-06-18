/*
3.2.7 vector互换容器功能描述:
实现两个容器内元素进行互换
函数原型;
swap(vec);//将vec与本身的元素互换

*/

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2;
	for (int i = 10; i > 0; i--) {
		v2.push_back(i);
	}
	printVector(v2);

	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

void test02() {
	vector<int> v;
	for (int i = 0; i < 1000000; i++) {
		v.push_back(i);
	}
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	v.resize(3);
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	vector<int>(v).swap(v);
	cout << v.capacity() << endl;
	cout << v.size() << endl;
}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}