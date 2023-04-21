/*
4.6.3继承中的对象模型
问题:从父类继承过来的成员，哪些属于子类对象中?
*/

#include<iostream>

using namespace std;

//继承中的对象模型
class Base
{
public:
	int m_A;

protected:
	int m_B;

private:
	int m_C;

};

class Son :public Base
{
public:
	int m_D;

};

//利用开发人员命令提示工具查看对象模型
//跳转路径
//cl /d1 reportSingleClassLayout类型 文件名

void test01()
{
	cout << "size of son" << sizeof(Son) << endl;
	//16
	//父类中所有非静态成员属性都会被子类继承下去
	//父类中私有成员属性 是被编译器隐藏了，因此访问不到 但是确实被继承了
}

int main()
{
	test01();

	system("pause");
	return 0;
}