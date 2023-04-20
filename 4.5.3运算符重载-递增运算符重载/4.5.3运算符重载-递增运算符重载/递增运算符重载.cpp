/*
4.5.3递增运算符重载
作用:通过重载递增运算符，实现自己的整型数据
*/

#include<iostream>

using namespace std;

//自定义整形
class MyInteger {
	friend ostream & operator<<(ostream& cout, MyInteger myint);

public:
	MyInteger(){
		m_Num = 0;
	}

	//重载前置++运算符
	MyInteger& operator++() {
		m_Num++;
		return *this;	//为了对一个数据进行递增操作
	}

	//重载后置++运算符
	MyInteger operator++(int) {	//int 占位参数 后置递增返回值
		//先 记录一下当时的结果
		MyInteger temp = *this;

		//后 递增
		++m_Num;

		//最后将记录结果做返回
		return temp;
	}

	MyInteger& operator--() {
		m_Num--;
		return *this;
	}

	MyInteger operator--(int) {
		//先 记录一下当时的结果
		MyInteger temp = *this;

		//后 递增
		m_Num--;

		//最后将记录结果做返回
		return temp;
	}

private:
	int m_Num;

};

//重载一下左移运算符
ostream& operator<<(ostream& cout, MyInteger myint) {
	cout << myint.m_Num;
	return cout;
}

void test01() {
	MyInteger myint;

	cout << ++myint << endl;
}

void test02() {
	MyInteger myint;

	cout << myint++ << endl;
	cout << myint << endl;

}

void test03() {
	MyInteger myint;

	cout << --myint << endl;
}

void test04() {
	MyInteger myint;

	cout << myint << endl;
	cout << --myint << endl;
	cout << myint << endl;

}

int main() {
	//test01();
	//test02();
	//test03();
	test04();

	system("pause");
	return 0;
}