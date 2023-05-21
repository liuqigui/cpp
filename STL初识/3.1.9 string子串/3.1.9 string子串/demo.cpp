/*
3.1.9 string子串功能描述:
·从字符串中获取想要的子串
函数原型:
string substr(int pos - 0,int w - npos) const;If返回由pos开始的n个字符组成的字符串

总结:灵活的运用求子串功能,可以在实际开发中获取有效的信息
*/

#include<iostream>
#include<string>

using namespace std;

void test01() {
	string str = "abcdef";

	string sub_str = str.substr(1, 3);

	cout << "sub_str = " << sub_str << endl;

	
}

//实用操作
void test02() {
	string email = "lisi@sina.com";

	//从邮件地址中 获取 用户信息
	int pos = email.find("@");
	string userName = email.substr(0, pos);
	cout << userName << endl;

}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}