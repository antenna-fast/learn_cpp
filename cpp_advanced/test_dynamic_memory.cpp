// Created by yaohua on 2022/4/29.

#include <iostream>

using namespace std;


int main(){
    double *p_var = NULL;  // 初始化为 null 的指针
    if (!(p_var = new double))  // 为变量请求内存
    {
        cout << "ERROR: out of memory ... " << endl;
    }
    *p_var = 100;
    cout << "*p_var: " << *p_var << endl;
    delete p_var;

    // 数组
    char *p_array = NULL;
    p_array = new char[20];

    delete p_array;

    return 0;
}