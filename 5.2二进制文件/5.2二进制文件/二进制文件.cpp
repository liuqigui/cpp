/*
5.2二进制文件
以二进制的方式对文件进行读写操作打开方式要指定为ios::binary

5.2.1写文件
二进制方式写文件主要利用流对象调用成员函数write
函敌原型:ostream& write(const char * buffer ,int len);
参数解释:字符指针buffer指向内存中一段存储空间。len是读写的字节数

总结:
·文件输出流对象可以通过write函数，以二进制方式写数据


5.2.2读文件
二进制方式读文件主要利用流对象调用成员函教read
函数原型: istream& read(char *buffer,int len);
参数解释:字符指针buffer指向内存中一段存储空间。len是读写的字节数。

*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//二进制文件	写文件
class Person
{
public:
	char m_Name[64];	//姓名
	int m_Age;	//年龄
};

void test01()
{
	//1.包含头文件
	//2.创建流对象
	ofstream ofs("person.txt", ios::out | ios::binary);
	//3.打开文件
	//ofs.open("person.txt", ios::out | ios::binary);
	//4.写文件
	Person p = { "张三", 18 };
	Person p1 = { "李四", 19 };
	Person p2 = { "王五", 20 };

	ofs.write((const char *)&p, sizeof(Person));
	ofs.write((const char *)&p1, sizeof(Person));
	ofs.write((const char *)&p2, sizeof(Person));

	//5.关闭
	ofs.close();
}

//读文件
void test02()
{
	//1.包含头文件
	//2.创建流对象
	ifstream ifs;
	//3.打开文件
	ifs.open("person.txt", ios::out | ios::binary);

	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	//4.读文件
	Person p;
	Person p1;
	Person p2;
	Person p3;

	ifs.read((char*)&p, sizeof(Person));
	ifs.read((char*)&p1, sizeof(Person));
	ifs.read((char*)&p2, sizeof(Person));
	ifs.read((char*)&p3, sizeof(Person));

	cout << p.m_Name << p.m_Age << endl;
	cout << p1.m_Name << p1.m_Age << endl;
	cout << p2.m_Name << p1.m_Age << endl;
	cout << p3.m_Name << p3.m_Age << endl;

	//5.关闭
	ifs.close();


}

int main()
{
	cout << "5.2二进制文件" << endl;
	//test01();
	test02();

	system("pause");
	return 0;
}