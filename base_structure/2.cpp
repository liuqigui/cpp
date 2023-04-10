#include <iostream>
using namespace std;
 
// 变量声明
extern int a, b;
extern int c;
extern float f;

class MyClass{
    public:
        static int class_var;
};

int MyClass::class_var = 30;

int main ()
{
  // 变量定义
  int a, b;
  int c;
  float f;
 
  // 实际初始化
  a = 10;
  b = 20;
  c = a + b;
 
  cout << c << endl ;
 
  f = 70.0/3.0;
  cout << f << endl ;

//初始化局部变量和全局变量
  int a1 =10;
  {
    int a1 = 20;
    std::cout << "块变量" << a1 << std::endl;
  }
  std::cout << "外部变量" << a1 << std::endl;

    //类变量
    std::cout << "类变量：" << MyClass::class_var << std::endl;

 
  return 0;
}