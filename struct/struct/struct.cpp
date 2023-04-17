#include<iostream>
#include<string>
#include<ctime>

using namespace std;

//1.创建一个学生的数据类型
//struct  Student
//{
//	//成员列表
//
//	//姓名
//	string name;
//
//	//年龄
//	int age;
//
//	//分数
//	int score;
//
//}s3;

//2.通过学生类型创建学生
//2.1struct Student s1
//2.2 struct Student s2 = {...}
//2.3 在定义结构体的时候顺便创建结构体变量

//8.3结构体数组
//语法：struct 结构体名 数组名[元素个数] = {{...},{...}}
//结构体数组
//8.3.1.定义结构体
//struct  Student
//{
//	//成员列表
//
//	//姓名
//	string name;
//
//	//年龄
//	int age;
//
//	//分数
//	int score;
//
//};

//8.4结构体指针
//struct Student
//{
//	string name;
//	int age;
//	int score;
//};

//8.5结构体嵌套
//struct  Student {
//	string name;
//	int age;
//	int score;
//};
//struct Teacher {
//	int id;
//	string name;
//	int age;
//	struct Student stu;
//};

////8.6结构体做函数参数
////作用：将结构体作为参数向函数中传递
////传递方式：值传递和地址传递
//struct  Student {
//	string name;
//	int age;
//	int score;
//};
////1.值传递
//void printStrudent1(Student s1) {
//	s1.age = 100;	//main里面并没有修改
//	cout << "name:" << s1.name << "age:" << s1.age << "scroe:" << s1.score << endl;
//}
////2.地址传递
//void printStrudent2(Student * p) {
//	p->age = 200;	//main里面也修改了
//	cout << "name:" << p->name << " age:" << p->age << " score:" << p->score << endl;
//}

////8.7结构体中const的使用场景
//struct  Student {
//	string name;
//	int age;
//	int score;
//};
////将函数中的形参改为指针可以减少内存空间，而且不会复制新的副本
//void printStrudent1(const Student *s1) {
//	//s1->age = 100;	//main里面并没有修改
//	cout << "name:" << s1->name << "age:" << s1->age << "scroe:" << s1->score << endl;
//}

////8.8结构体案例
//struct Student {
//	string sName;
//	int score;
//};
//struct Teacher {
//	string tName;
//	struct Student sArray[5];
//};
//void allocateSpace(Teacher tArray[], int len) {
//
//	string nameSeed = "ABCDE";
//
//	for (int i = 0; i < len; i ++ ) {
//		tArray[i].tName = "Teacher_";
//		tArray[i].tName += nameSeed[i];
//
//		//通过循环给每个老师所带的学生赋值
//		for (int j = 0; j < 5; j++) {
//			tArray[i].sArray[j].sName = "Student_";
//			tArray[i].sArray[j].sName += nameSeed[j];
//
//			int random = rand() % 61 + 40;	//随机数40~99
//			tArray[i].sArray[j].score = random;
//		}
//	}
//}
//void printInfo(struct Teacher tArray[], int len) {
//	for (int i = 0; i < len; i++) {
//		cout << "teacher_name:" << tArray[i].tName << endl;
//		for (int j = 0; j < 5; j++) {
//			cout << "student_name:" << tArray[i].sArray[j].sName << " ";
//			cout << "student_score:" << tArray[i].sArray[j].score<< endl;
//		}
//	}
//}

//8.9案例
struct Hero
{
	string name;
	int age;
	string gendar;
};
//冒泡排序 实现年龄升序 
void bubbleSort(Hero heroArray[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (heroArray[j].age > heroArray[j + 1].age) {
				Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}
//打印输出
void printInfo(Hero heroArray[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "姓名:" << heroArray[i].name << " age:" << heroArray[i].age << " gendar:" << heroArray[i].gendar << endl;
	}
}

int main() {
	////2.1struct Student s1
	//struct Student s1;	//struct关键字可以省略
	//s1.name = "张三";
	//s1.age = 18;
	//s1.score = 100;

	//cout << "name:" << s1.name << "age:" << s1.age << "scroe:" << s1.score << endl;

	////2.2 struct Student s2 = {...}
	//struct Student s2 = { "李四", 19, 80 };
	//cout << "name:" << s2.name << "age:" << s2.age << "scroe:" << s2.score << endl;

	////2.3 在定义结构体的时候顺便创建结构体变量
	//s3.name = "王五";
	//s3.age = 20;
	//s3.score = 60;
	//cout << "name:" << s3.name << "age:" << s3.age << "scroe:" << s3.score << endl;
	


	//8.3.2.创建结构体数组
	//struct Student stuArray[3] = 
	//{
	//	{"张三", 18, 100},
	//	{"李四", 28, 99},
	//	{"王五", 38, 66}
	//};
	//stuArray[2].name = "赵六";
	//stuArray[2].age = 80;
	//stuArray[2].score = 60;

	//for (int i = 0; i < 3; i++) {
	//	cout << "name:" << stuArray[i].name
	//		<< "age:" << stuArray[i].age
	//		<< "score:" << stuArray[i].score << endl;
	//}

	////8.4.1创建结构体变量
	//struct Student s = { "张三", 18 ,100 };

	////8.4.2通过指针指向结构体变量
	//Student * p = &s;
	//
	////8.4.3通过指针访问结构体变量
	//cout << "name:" << p->name << "age:" << p->age << "score:" << p->score << endl;

	////8.5.1创建结构体变量
	//Teacher t;
	//t.id = 10000;
	//t.name = "老王";
	//t.age = 50;
	//t.stu.name = "小王";
	//t.stu.age = 20;
	//t.stu.score = 60;

	//cout << t.id << t.name << t.age << t.stu.name << t.stu.age << t.stu.score << endl;

	////8.6.1创建结构体变量
	//Student s;
	//s.name = "张三";
	//s.age = 20;
	//s.score = 85;
	//cout << "name:" << s.name << "age:" << s.age << "scroe:" << s.score << endl;
	//printStrudent1(s);
	//cout << "name:" << s.name << "age:" << s.age << "scroe:" << s.score << endl;
	//printStrudent2(&s);
	//cout << "name:" << s.name << "age:" << s.age << "scroe:" << s.score << endl;

	////8.7.1创建结构体变量
	//Student s = { "张三", 15, 70 };
	////打印结构体信息
	//printStrudent1(&s);
	
	////8.8.1创建结构体变量
	//Teacher tArray[3];
	//
	////随机数种子
	//srand((unsigned int)time(NULL));
	////8.8.2开始赋值
	//int len = sizeof(tArray) / sizeof(tArray[0]);
	//allocateSpace(tArray, len);
	//printInfo(tArray, len);

	//8.9
	Hero heroArray[5] = {
		{"刘备", 23, "男"},
		{"关羽", 22, "男"},
		{"张飞", 20, "男"},
		{"赵云", 21, "男"},
		{"貂蝉", 19, "女"},

	};

	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	for (int i = 0; i < len; i++) {
		cout << "姓名:" << heroArray[i].name << " age:" << heroArray[i].age << " gendar:" << heroArray[i].gendar << endl;
	}

	bubbleSort(heroArray, len);
	printInfo(heroArray, len);

	return 0;
}