/*
2.5.2 Vector存放自定义数据类型
学习目标: vector中存放自定义数据类型，并打印输出



*/

#include<iostream>
#include<string>

#include<vector>
using namespace std;

class Person
{
public:
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test01() {
	vector<Person> v;

	Person p1("aa", 10);
	Person p2("bb", 20);
	Person p3("cc", 30);
	Person p4("dd", 40);
	Person p5("ee", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//cout << "name:" << (*it).m_Name << " age:" << (*it).m_Age << endl;
		cout << "name:" << it->m_Name << " age:" << it->m_Age << endl;
	}

}


//指针
void test02() {
	vector<Person *> v;

	Person p1("aa", 10);
	Person p2("bb", 20);
	Person p3("cc", 30);
	Person p4("dd", 40);
	Person p5("ee", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "name:" << (*it)->m_Name << " age:" << (*it)->m_Age << endl;
	}

}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}