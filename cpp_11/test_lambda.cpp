//
// Created by yaohua on 2022/5/7.
//

// ref: https://www.cnblogs.com/DswCnblog/p/5629165.html

#include <iostream>

using namespace std;


int main(){

    cout << "test lambda" << endl;

    auto a = 1;

    // 捕获列表类型
    // 不导入任何外部变量 []       required
    // parameter list: ()       optional
    // return type: -> type     optional
    // function body            required

    // demo : test return type    
    auto f = [](int a) -> int{ return a+1; };
    cout << "f(1): " << f(1) << endl;
    
    // demo 1: capture list
    // 1.1: 传值 [=]
    // implicit capture, not indicate the var 
    auto f2 = [=]{ cout << "a val: " << a << endl; };
    a = a+1;    // modify the value of a after define f2
    // cout << "a: " << a << endl;  // a = 2
    f2();       // note the output value, we find that, the value of a is old (before modify)

    // 1.2: 引用传递 [&]
    // implicit capture, not indicate the var 
    auto f3 = [&]{ cout << "a val: " << a << endl; };
    a += 1;     // modify the value of a after define f3
    f3();

    // 1.3: ref and value
    // only ref some var 
    int b = 0;
    auto f4 = [=, &b] { cout << "a: " << a << " b: " << b << endl; };
    a += 1;
    b += 1;
    f4();

    return 0;
}