/*
4.5.2左移运算符重载
作用:可以输出自定义数据类型
*/

#include<iostream>

using namespace std;

//左移运算法重载
class Person {
	friend ostream & operator<<(ostream &cout, Person &p);

public:
	Person(int a, int b) {
		m_A = a;
		m_B = b;
	}

	//利用成员函数重载 左移运算符
	//不会利用成员函数来重载 左移运算符
	/*void operator<<(Person &p) {

	}*/
private:
	int m_A;
	int m_B;

};

//只能利用全局函数重载 左移运算符
ostream & operator<<(ostream &cout, Person &p) { //本质 opeartor<< (cout, p)  简化 cout << p
	cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return cout;
}

void test01() {
	Person p(10, 10);
	/*p.m_A = 10;
	p.m_B = 10;*/

	cout << p << endl ;

}

int main() {

	test01();

	system("pause");
	return 0;
}