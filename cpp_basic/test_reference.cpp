//
// Created by yaohua on 2022/4/27.
//

#include <iostream>


using namespace std;

int main(){
    cout << "test reference " << endl;

    int var_1 = 999;
    int var_2 = 666;

    int &r_var_1 = var_1;  // 引用变量var_1必须初始化

    cout << "r_var_1: " << r_var_1 << endl;

    // var_1与r_var_1的地址是相同的
    cout << "p_var_1: " << &var_1 << endl;
    cout << "p_r_var_1: " << &r_var_1 << endl;

    return 0;
}