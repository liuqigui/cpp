//数据类型
/*
整型:short(两个字节，-32768~32767) int(四个字节) long（四个字节） longlong(8个字节)

sizeof关键字(利用sizeof输出数据类型占用内存大小，sizeof(数据类型/变量))

实型（浮点数）：float(单精度) double(双精度) 默认输出6位有效数字

字符型：char(一个字节)

转义字符：\n:换行 \\:\ \t:制表

字符串：char name[] = "helloworld"
string name = "",#include<string>

布尔类型：true:0,false:0,占用内存为1。非0的值都是真。
*/
#include<iostream>
#include<string>
using namespace std;

int main(){
//float
    float f1 = 3.14f;
    cout << f1 << sizeof(float) << endl;

    double d1 = 3.14;
    cout << d1 << sizeof(double) <<endl;
    //3e2 = 3*10^2
    //3e-2 = 3*0.1^2
    cout << 3e2 << 3e-2 << endl;

//char
    char ch = 'a'; //必须是单引号，''里面也必须是一个字符
    cout << ch << sizeof(char) << endl;
    cout << (int)ch << endl; //ASCII编码

//转义字符
    cout << "\n \\ \t helloworld" << endl;

//字符串
    char str[] = "hellostr";    //char name[],=后面是""
    cout << str << endl;
    string str1 = "hellostring";    //string name,头文件<string>
    cout << str1 <<endl;

//布尔型
    cout << true << false << endl;

//输入数据  cin
    float f2 = 3.14f;
    cin >> f2;
    cout << f2 << endl;
    int a;
    cin >> a;
    cout << a << endl;
    string str2;
    cin >> str2;
    cout << str2 << endl;
    bool flag = false;
    cin >> flag;
    cout << flag << endl;

    system("pause");

    return 0;
}