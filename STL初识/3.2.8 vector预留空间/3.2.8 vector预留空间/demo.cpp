/*
3.2.8 vector预留空间功能描述:
·减少vector在动态扩展容量时的扩展次数
函数原型:
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。

*/

#include<iostream>
#include<vector>
using namespace std;

void test01() {
	vector<int> v1;
	int num = 0;
	int * p = NULL;

	v1.reserve(100000);

	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);
		if (p != &v1[0]) {
			p = &v1[0];
			num++;
		}
	}
	cout << num << endl;

	cout << v1.capacity() << endl;
	cout << v1.size() << endl;

}

int main()
{
	test01();

	system("pause");
	return 0;
}