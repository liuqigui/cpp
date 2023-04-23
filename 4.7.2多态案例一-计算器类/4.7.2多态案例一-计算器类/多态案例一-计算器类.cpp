/*
4.7.2多态案例一-计算器类
案例描述:
分别利用普通写法和多态技术，设计实现两玲操作数进行运算的计算器类

多态的优点:|
·代码组织结构清晰
·可读性强
·利于前期和后期的扩展以及维护

总结:C++开发提倡利用多态设计程序架构,因为多态优点很多


*/

#include<iostream>
#include<string>

using namespace std;

class Calculator
{
public:

	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
	}

	int m_Num1;
	int m_Num2;
};

//多态 扩展新的功能，需要修改代码
//开闭原则：对扩展进行开放，对修改进行关闭

void test01()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 12;

	cout << c.m_Num1 << "+" << c.m_Num2 << " = " << c.getResult("+") << endl;
	
	cout << c.m_Num1 << "-" << c.m_Num2 << " = " << c.getResult("-") << endl;
	
	cout << c.m_Num1 << "*" << c.m_Num2 << " = " << c.getResult("*") << endl;

}

//利用多态实现计算器

//多态好处：
//1.组织结构清晰
//2.可读性强
//3.对于前期和后期扩展以及维护性高

//实现计算器的抽象类

class AbstractCalculator
{
public:
	virtual int getResult(string s)
	{
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//加法计算器类
class AddCalcultor : public AbstractCalculator
{
public:

	int getResult(string s)
	{
		if(s == "+")
			return m_Num1 + m_Num2;
	}

};

//减法计算器类
class SubCalcultor : public AbstractCalculator
{
public:

	int getResult(string s)
	{
		if(s == "-")
			return m_Num1 - m_Num2;
	}

};

//乘法计算器类
class MulCalcultor : public AbstractCalculator
{
public:

	int getResult(string s)
	{
		if(s == "*")
			return m_Num1 * m_Num2;
	}

};

void test02()
{
	//多态使用
	//父类指针或者引用指向子类对象

	//加法运算
	AbstractCalculator * abc = new AddCalcultor;
	abc->m_Num1 = 10;
	abc->m_Num2 = 12;

	cout << abc->m_Num1 << "+" << abc->m_Num2 << " = " << abc->getResult("+") << endl;
	delete abc;

	//减法运算
	abc = new SubCalcultor;
	abc->m_Num1 = 10;
	abc->m_Num2 = 12;

	cout << abc->m_Num1 << "-" << abc->m_Num2 << " = " << abc->getResult("-") << endl;
	delete abc;


	//乘法运算
	abc = new MulCalcultor;
	abc->m_Num1 = 10;
	abc->m_Num2 = 12;

	cout << abc->m_Num1 << "*" << abc->m_Num2 << " = " << abc->getResult("*") << endl;
	delete abc;
}

int main()
{
	cout << "多态案例一-计算器类" << endl;
	//test01();
	test02();

	system("pause");
	return 0;
}