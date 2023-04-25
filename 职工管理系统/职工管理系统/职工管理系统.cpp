/*
1、管理系统需求
职工管理系统可以用来管理公司内所有员工的信息
本教程主要利用C++来实现一个甚于多态的职工管理系统

公司中职工分为三类:普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工岗位、以及职责
普通员工职责:完成经理交给的任务
经理职责:完成老板交给的任务，并下发任务给员工
老板职责:管理公司所有事务

管理系统中需要实现的功能如下:
·退出管理程序:退出当前管理系统
·增加职工信息:实现批量添加职工功能，将信息录入到文件中，职工信息为:职工编号、姓名、部门编号
·显示职工信息:显示公司内部所有职工的信息
·删除离职职工:按照编号删除指定的职工
·修改职工信息:按照编号修改职工个人信息
·查找职工信息:按照职工的编号或者职工的姓名进行查找相关的人员信息
·按照编号排序:按照职工编号，进行排序,排序规则由用户指定
·清空所有文档:清空文件中记录的所有职工信息(清空前需要再次确认，防止误删)

*/

#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"

using namespace std;

int main()
{

	//测试代码
	/*Worker * worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;*/

	class WorkerManager wm;

	int choice = 0;
	while (true) {
		//展示菜单成员函数
		wm.Show_Menu();

		cout << "请输入您的选择：" << endl;

		cin >> choice;

		switch (choice) {
		case 0:		//退出管理程序
			wm.exitSystem();
			break;
		case 1:		//增加职工信息
			wm.Add_Emp();
			break;
		case 2:		//显示职工信息
			wm.show_Emp();
			break;
		case 3:		//删除离职职工
			wm.Del_Emp();
			break;
		/*{
			int ret = wm.IsExist(5);
			if (ret != -1) {
				cout << "存在" << endl;
			}
			else {
				cout << "不存在" << endl;
			}
			break;
		}*/
		case 4:		//修改职工信息
			wm.Mod_Emp();
			break;
		case 5:		//查找职工信息
			wm.Find_Emp();
			break;
		case 6:		//按照编号排序
			wm.Sort_Emp();
			break;
		case 7:		//清空所有文档
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}



	system("pause");
	return 0;
}