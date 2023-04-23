/*
案例描述:
电脑主要组成部件为CPU(用于计算)，显卡(用于显示)，内存条(用于存储)
将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商
创建电脑类提供让电脑工作的函数,并且调用每个零件工作的接口
测试时组装三台不同的电脑进行工作

*/

#include<iostream>

using namespace std;

//抽象的cpu类
class CPU
{
public:
	//抽象的计算函数
	virtual void calculate() = 0;
	
};

//抽象的显卡类
class VideoCard
{
public:
	//抽象的显示函数
	virtual void display() = 0;
};

//抽象的内存条类
class Memory
{
public:
	virtual void storage() = 0;
};

//电脑类
class Computer
{
public:
	Computer(CPU * cpu, VideoCard * vc, Memory * mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	//提供工作的函数
	void work()
	{
		//让零件工作起来，调用接口
		m_cpu->calculate();

		m_vc->display();

		m_mem->storage();
	}

	~Computer()
	{
		//释放CPU零件
		if (m_cpu != NULL)
		{
			delete m_cpu;
		}

		//释放显卡零件
		if (m_vc != NULL)
		{
			delete m_vc;
		}

		//释放内存条零件
		if (m_mem != NULL)
		{
			delete m_mem;
		}
	}

private:
	CPU * m_cpu;	//cpu的零件指针
	VideoCard * m_vc;	//显卡的零件指针
	Memory * m_mem;	//内存条的零件指针
};

//具体厂商
class IntelCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel的cpu开始计算了!!!" << endl;
	}

};

class IntelVideoCard : public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel的显卡开始显示了!!!" << endl;
	}

};

class IntelMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel的内存条开始存储了!!!" << endl;
	}

};

//Lenovo
class LenovoCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo的cpu开始计算了!!!" << endl;
	}

};

class LenovoVideoCard : public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo的显卡开始显示了!!!" << endl;
	}

};

class LenovoMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo的内存条开始存储了!!!" << endl;
	}

};

void test01()
{
	//第一台电脑零件
	CPU * interCPU = new IntelCPU;
	VideoCard * intelCard = new IntelVideoCard;
	Memory * intelMem = new IntelMemory;

	//创建第一台电脑
	Computer * computer1 = new Computer(interCPU, intelCard, intelMem);
	computer1->work();
	delete computer1;

	//第二台电脑
	cout << "------------------------------------------------" << endl;
	cout << "第二台电脑" << endl;
	Computer * computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;

	//第三台电脑
	cout << "------------------------------------------------" << endl;
	cout << "第三台电脑" << endl;
	Computer * computer3 = new Computer(new LenovoCPU, new LenovoVideoCard, new IntelMemory);
	computer3->work();
	delete computer3;

}

int main()
{
	cout << "电脑组装" << endl;
	test01();

	system("pause");
	return 0;
}