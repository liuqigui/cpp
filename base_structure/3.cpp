#include <iostream>
using namespace std;
 
int main()
{
   cout << "Hello\tWorld\n\n";

    string greeting = "hello, runoob";
    cout << greeting;
    cout << "\n";     // 换行符
    string greeting2 = "hello, \
                       runoob";
    cout << greeting2 << endl;

    const int NUM = 10;
    const int* ptr = &NUM;
    int const* ptr2 = &NUM;
    // cout << NUM << endl;
    cout << NUM << " " << ptr << endl;

    signed int num1 = -10; // 定义有符号整型变量 num1，初始值为 -10
    unsigned int num2 = 20; // 定义无符号整型变量 num2，初始值为 20

    short int num3 = 10; // 定义短整型变量 num1，初始值为 10
    long int num4 = 100000; // 定义长整型变量 num2，初始值为 100000

    long long int num5 = 10000000000; // 定义长长整型变量 num1，初始值为 10000000000

    float num6 = 3.14f; // 定义单精度浮点数变量 num1，初始值为 3.14
    double num7 = 2.71828; // 定义双精度浮点数变量 num2，初始值为 2.71828

    bool flag = true; // 定义布尔类型变量 flag，初始值为 true

    char ch1 = 'a'; // 定义字符类型变量 ch1，初始值为 'a'
    wchar_t ch2 = L'你'; // 定义宽字符类型变量 ch2，初始值为 '你'

    cout << num1 << num2 << flag << ch1 << ch2 << endl;
    cout << ch1 <<"  "<< ch2 << endl;

    volatile int num11 = 20; // 定义变量 num，其值可能会在未知的时间被改变
    cout << num11 << endl;


   return 0;
}