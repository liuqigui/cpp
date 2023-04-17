#include<iostream>
#include<string>

using namespace std;

#define MAX 1000	//最大人数

//封装函数显示界面，void showMenu()
void shouwMenu() {
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

//联系人struct
struct Person
{
	string m_Name;	//姓名
	int m_Gendar;	//性别	1 男 2 女
	int m_Age;		//年龄
	string m_Phone;	//电话
	string m_Addr;	//住址
};

//通讯录结构体
struct Addressbooks
{
	Person personArray[MAX];	//通讯录中保存的联系人数组
	int m_Size;	//通讯录中人员个数
};

//1.添加联系人
void addPerson(Addressbooks * abs) {
	//判断通讯录是否满了，如果满了就不再添加了
	if (abs->m_Size == MAX) {
		cout << "通讯录已满！！！" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;

		while (true)
		{	
			//如果输入的是1或者2可以退出循环，如果输入有误则重新输入
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Gendar = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;	//清空有效！

		cout << "恭喜你，添加成功！" << endl;
		system("pause");
		system("cls");	//清屏
	}

}

//2.显示所有的联系人
void showPerson(Addressbooks * abs) {
	//判断通讯录中的人数是否为0，如果为0，提示记录为空
	if (abs->m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Gendar == 1?"男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;

		}
	}
	system("pause");
	system("cls");	//清屏
}

//3.删除联系人

//3.1 封装检测联系人是否存在,1下表编号，0返回-1
int isExist(Addressbooks * abs, string name) {	//通讯录和对比姓名
	for (int i = 0; i < abs->m_Size; i++) {
		//找到输入的姓名
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
		else {
			return -1;
		}
	}
}

//3.2 封装删除联系人函数
void deletPerson(Addressbooks * abs) {
	cout << "请输入您要删除的联系人：" << endl;
	
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {	//将ret后的数据向前移动，并m.size-1
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功！" << endl;
	}
	else {
		cout << "查无此人!" << endl;
	}

	system("pause");
	system("cls");
}

//4.查找联系人
void findPerson(Addressbooks * abs) {
	cout << "请输入您要查找的联系人：" << endl;

	string name;
	cin >> name;
	
	int ret = isExist(abs, name);

	if (ret != -1) {	//找到了
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Gendar == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else {	//未找到
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

//5.修改联系人
void modifyPerson(Addressbooks * abs) {
	cout << "请输入您要修改的联系人：" << endl;
	
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {	//找到了
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;

		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {	//输入正确！
				abs->personArray[ret].m_Gendar = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功！" << endl;

	}
	else {	//未找到
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

//6.清空联系人
void cleanPerson(Addressbooks * abs) {
	int i;
	cout << "请确认清空：" << endl;
	cout << "1 --- 确认" << endl;
	cout << "2 --- 取消" << endl;
	cin >> i;
	if (i == 1) {
		abs->m_Size = 0;
		cout << "通讯录已经清空！" << endl;
		system("pause");
		system("cls");
	}
	else {
		system("pause");
		system("cls");
	}

}

int main() {
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;


	int select = 0;	//创建用户选择输入的变量

	while (true)
	{
		//菜单的调用
		shouwMenu();

		cin >> select;
		switch (select)
		{
		case 1:	//添加联系人
			addPerson(&abs);	//利用地址传递，可以修改实参
			break;
		case 2:	//显示联系人
			showPerson(&abs);
			break;
		case 3: {//删除联系人
			deletPerson(&abs);
			//cout << "请输入删除联系人姓名：" << endl;
			//string name;
			//cin >> name;

			//if (isExist(&abs, name) == -1) {
			//	cout << "查无此人" << endl;
			//}
			//else {
			//	cout << "找到此人！" << endl;
			//}
			break; 
		}
		case 4:	//查找联系人
			findPerson(&abs);
			break;
		case 5:	//修改联系人
			modifyPerson(&abs);
			break;
		case 6:	//清空联系人
			cleanPerson(&abs);
			break;
		case 0:	//退出通讯录
			cout << "欢迎下次使用" << endl;
			//system("pause");
			goto exit_loop;
			break;
		default:
			cout << "请摁下正确按键" << endl;
			break;
		}
		//退出功能：退出通讯录系统
	}

exit_loop:
	system("pause");
	return 0;
}