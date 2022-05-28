//
// Created by yaohua on 2022/4/27.
//

#include <iostream>


using namespace std;

int main(){
    // 标准输入输出
    // 输出
    char var_str[] = "Hello, C++!";
    cout << var_str << endl;

    // 输入
    char name[50];
    cout << "input your name: ";
    cin >> name;
    cout << "your name: " << name << endl;

    // error stream
    cerr << "ERROR message: " << endl;

    // log
    clog << "log stream " << endl;


    return 0;
}