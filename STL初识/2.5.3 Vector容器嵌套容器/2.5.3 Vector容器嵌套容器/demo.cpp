/*
2.5.3 Vector容器嵌套容器
学习目标:容器中嵌套容器，我们将所有数据进行遍历输出

*/

#include<iostream>
#include<vector>

using namespace std;

void test01()
{
	vector<vector<int>> v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << " ";
		}
		cout << endl;
	}

}

int main()
{
	test01();

	system("pause");
	return 0;
}