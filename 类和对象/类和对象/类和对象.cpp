/*
4 类和对象
C++面向对象的三大特性为:封装、继承、多态
C++认为万事万物都皆为对象，对象上有其属性和行为
例如:
人可以作为对象，属性有姓名、年龄、身高、体重.....行为有走、跑、跳、吃饭、唱歌....车也可以作为对象，属性有轮胎、方向盘、车灯....行为有载人、放音乐、放空调...
具有相同性质的对象，我们可以抽象称为类，人属于人类，车属于车类

4.1 封装
4.1.1 封装的意义
封装是c++面向对象三大特性之一
封装的意义：
	将属性和行为作为一个整体，表现生活中的事物
	将属性和行为加以权限控制

	封装的意义一：
		在设计类的时候，属性和行为写在一起，表现事物
		语法：class 类名{	访问权限：属性		/行为}；
	封装意义二:
		类在设计时，可以把属性和行为放在不同的权限下，加以控制访问权限有三种: 
			1. public公共权限		成员在类内可以访问 类外也可以访问
			2. protected保护权限	成员在类内可以访问 类外不可以访问 子类也可以访问父类中保护的内容
			3. private私有权限		成员在类内可以访问 类外不可以访问 子类不可以访问父类中保护的内容
4.1.2 struct和class区别
	在C++中struct和class唯一的区别就在于默认的访问权限不同区别:
	- struct默认权限为公共
	- class默认权限为私有
4.1.3 成员属性设置为私有
	优点1∶将所有成员属性设置为私有，可以自己控制读写权限
	优点2:对于写权限，我们可以检测数据的有效性
*/
#include<iostream>
#include<string>

using namespace std;

const double PI = 3.14;

//设计一个圆类，求圆的周长
//圆求周长的公式:2 * PI * 半径
class Circle {
	//访问权限
public:
	//属性 变量
	int m_r;	//半径
	
	//行为 函数 获取圆的周长
	double calculateZC() {
		return 2 * PI * m_r;
	}
};

//设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
class Student {
	//访问权限
public:
	//类中的属性和行为 统一成为 成员
	//属性 成员属性 成员变量
	//行为 成员函数 成员方法

	string m_Name;
	int m_Id;

	void showStudent() {
		cout << "姓名：" << m_Name << "\t 学号：" << m_Id << endl;
	}

	//自己写
	//void prinfShow() {
	//	cout << "name:" << m_Name << endl;
	//	cout << "Id;" << m_Id << endl;
	//}

	//给姓名赋值
	void setName(string name) {
		m_Name = name;
	}

	//给学号赋值
	void setId(int id) {
		m_Id = id;
	}
};

class Person {
public:
	//公共权限
	string m_Name;

protected:
	string m_Car;

private:
	int m_Password;
	
public:
	void func() {
		m_Name = "张三";
		m_Car = "奔驰";
		m_Password = 123456;
	}

};

class C1 {
	int m_A;	//默认私有
};

struct C2
{
	int m_A;	//默认公有
};

class Person1 {
public:
	//设置姓名
	void setName(string name) {	
		m_Name = name;
	}

	//获取姓名
	string getName() {
		return m_Name;
	}

	//获取年龄
	int getAge() {
		//m_Age = 18;
		return m_Age;
	}
	//年龄为0-150之间
	void setAge(int age) {
		if (age < 0 || age >150) {
			cout << "输入年龄有误！" << endl;
			return;
		}
		else {
			m_Age = age;
		}
	}

	//情人	只写
	void setLover(string lover) {
		m_Lover = lover;
	}

private:
	//姓名	可读可写
	string m_Name;

	//年龄	只读
	int m_Age;

	//情人	
	string m_Lover;
};

int main() {

	//通过圆类 创建具体的圆
	Circle c1;	//实例化，通过一个类 创建一个对象的过程
	//给圆对象的属性（半径）进行赋值
	c1.m_r = 10;

	cout << "○的周长：" << c1.calculateZC() << endl;

	Student s1;
	s1.m_Name = "刘其贵";
	s1.m_Id = 202420049;

	cout << "show:" << endl;
	//s1.prinfShow();
	s1.showStudent();

	Student s2;
	s2.m_Name = "李四";
	s2.m_Id = 2;
	s2.showStudent();

	Student s3;
	s3.setName("张达");
	s3.setId(21);
	s3.showStudent();

	Person p1;
	p1.m_Name = "李四";
	//p1.m_Car = "拖拉机";	//保护权限内容不可以访问
	//p1.m_Password = 123321;	//私有权限内容不可以访问

	cout << "4.1.2 struct和class区别" << endl;
	C1 c2;
	//c2.m_A = 100;	//不可以访问，默认私有
	C2 c3;
	c3.m_A = 100;	//不可以访问，默认公有
	cout << "struct:" << c3.m_A << endl;

	cout << "4.1.3 struct和class区别" << endl;
	Person1 p;
	p.setName("张达");
	cout << "姓名为：" << p.getName() << endl;
	p.setAge(13);
	cout << "年龄为：" << p.getAge() << endl;
	p.setLover("小芳");


	system("pause");
	return 0;
}