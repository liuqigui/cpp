/*
4.6继承
继承是面向对象三大特性之一
有些类与类之间存在特殊的关系,例如下图中:

我们发现，定义这些类时，下级别的成员除了拥有上一级的共性，还有自己的特性。
这个时候我们就可以考虑利用继承的技术，减少重复代码


4.6.1继承的基本语法
例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中心内容不同
接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承存在的意义以及好处

继承的好处：减少重复代码
语法：class子类 ：继承类 父类
子类 也称为 派生类
父类 也成为 基类

*/

#include<iostream>
#include<string>

using namespace std;

//普通实现页面
//class Java
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登陆、注册。。。。（公共头部）" << endl;
//	}
//
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图。。。（公共底部）" << endl;
//	}
//
//	void left()
//	{
//		cout << "Java、Python、C++。。。（公共分类列表）" << endl;
//	}
//
//	void centent()
//	{
//		cout << "Java学科视频" << endl;
//	}
//
//};
//
//class Python
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登陆、注册。。。。（公共头部）" << endl;
//	}
//
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图。。。（公共底部）" << endl;
//	}
//
//	void left()
//	{
//		cout << "Java、Python、C++。。。（公共分类列表）" << endl;
//	}
//
//	void centent()
//	{
//		cout << "Python的学科视频" << endl;
//	}
//
//};
//
//class CPP
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登陆、注册。。。。（公共头部）" << endl;
//	}
//
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图。。。（公共底部）" << endl;
//	}
//
//	void left()
//	{
//		cout << "Java、Python、C++。。。（公共分类列表）" << endl;
//	}
//
//	void centent()
//	{
//		cout << "C++的学科视频" << endl;
//	}
//
//};

//公共的内容
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登陆、注册。。。。（公共头部）" << endl;
	}
		
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图。。。（公共底部）" << endl;
	}
		
	void left()
	{
		cout << "Java、Python、C++。。。（公共分类列表）" << endl;
	}
};

//Java页面
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Java学科视频" << endl;
	}
};

//Python页面
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};

//CPP页面
class CPP :public BasePage
{
public:
	void content()
	{
		cout << "CPP学科视频" << endl;
	}
};

void test01() {

	cout << "java下载视频的页面如下：" << endl;
	Java ja;
	ja.header();
	ja.left();
	ja.content();
	ja.footer();

	cout << "********************************************************" << endl;

	cout << "Python下载视频的页面如下：" << endl;
	Python py;
	py.header();
	py.left();
	py.content();
	py.footer();

	cout << "********************************************************" << endl;

	cout << "C++下载视频的页面如下：" << endl;
	CPP cpp;
	cpp.header();
	cpp.left();
	cpp.content();
	cpp.footer();

}

int main()
{
	test01();

	system("pause");
	return 0;
}