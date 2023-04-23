/*
4.7.4多态案例二-制作饮品案例

描述:
制作饮品的大数流程为:寿水-冲泡-倒入杯中-加入辅料

利用多态技术实现本案例,提供抽象制作饮品基类，提供子类制作咖啡和茶叶

*/

#include<iostream>

using namespace std;

class AbstructDrinking
{
public:

	//煮水
	virtual void Boil() = 0;

	//冲泡
	virtual void Brew() = 0;

	//倒入杯中
	virtual void PourInCup() = 0;

	//加入作料
	virtual void PutSomething() = 0;

	//制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

class Coffee : public AbstructDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮农夫山泉" << endl;
	}

	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}

	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}

	//加入作料
	virtual void PutSomething()
	{
		cout << "加入糖和牛奶" << endl;
	}
};

class Tea : public AbstructDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮矿泉水" << endl;
	}

	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}

	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入玻璃杯中" << endl;
	}

	//加入作料
	virtual void PutSomething()
	{
		cout << "加入柠檬" << endl;
	}
};

//制作函数
void doWork(AbstructDrinking * abs)
{
	abs->makeDrink();
	delete abs;
}

void test01()
{
	//制作咖啡
	doWork(new Coffee);

	cout << "---------------------------------" << endl;
	//制作茶叶
	doWork(new Tea);

}

int main()
{
	cout << "多态案例二-制作饮品案例" << endl;
	test01();

	system("pause");
	return 0;
}