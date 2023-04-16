/*
数组

一维数组

二维数组

*/

#include<iostream>
using namespace std;

int main(){
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << sizeof(arr) << sizeof(arr[0]) << sizeof(arr) / sizeof(arr[0]) << endl;

//元素逆置
    int start = 0;
    int end = sizeof(arr) /sizeof(arr[0]) -1;
    int temp;

    for(int i=0;i<=end;i++){
        cout << "输出" << arr[i] << endl;
    }

    for(int i=start, j = end;i < (start + end) / 2; i++, j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for(int i=0;i<=end;i++){
        cout << "输出后" << arr[i] << endl;
    }

//冒泡排序
    int arr1[9] = {4, 2, 8, 0, 5, 7, 1, 3, 9};
    int start1 = 0;
    int end1 = sizeof(arr1) /sizeof(arr1[0]) -1;
    int temp1;

    for(int i=0;i<=end1;i++){
        cout << "冒泡前1：" << arr1[i] << endl;
    }

    for(int i = end1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr1[j]<arr1[j+1]){
                temp1 = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp1;
            }
            
        }
    }
    for(int i=0;i<=end1;i++){
        cout << "冒泡后：" << arr1[i] << endl;
    }

    return 0;
}