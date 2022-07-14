//
// Created by yaohua on 2022/5/7.
//

#include <iostream>

using namespace std;


int main(){

    cout << "test lambda" << endl;

    auto a = 1;

    // 最简单的lambda

    // 捕获列表类型
    // 不导入任何外部变量 []
    auto f = [](int a) -> int{return a+1;};
    cout << f(1) << endl;

    // 传值 [=]
    auto f2 = [=]{cout << "a val: " << a << endl;};
    a = a+1;
    f2();  // 注意输出的alue!

    // 引用传递 [&]

    return 0;
}