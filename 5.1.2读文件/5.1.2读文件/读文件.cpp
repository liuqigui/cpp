/*
5.1.2读文件
读文件与写文件步骤相似,但是读取方式相对于比较多
读文件步骤如下:
1.包含头文件
#include <fstream>
2.创建流对象
ifstream is;
3.打开文件并判断文件是否打开成功
ifs.open("文件路径"",打开方式);
4.读数据
四种方式读取
5.关闭文件
ifs.close();


总结:
·读文件可以利用ifstream ,或者fstream类
·利用is_open函教可以判断文件是否打开成功 
·close关闭文件
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void test01()
{
	//1.包含头文件
	//2.创建流对象
	ifstream ifs;
	//3.打开文件并判断文件是否打开成功
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	//4.读数据
	//第一种
	/*char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}*/

	//第二种
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}*/

	//第三种
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

	//第四种 不推荐
	//char c;
	//while ((c = ifs.get()) != EOF)	//EOF  end of file
	//{
	//	cout << c << endl;
	//}

	//5.关闭文件
	ifs.close();

}

int main()
{
	cout << "读文件" << endl;
	test01();

	system("pause");
	return 0;
}