//
// Created by yaohua on 2022/5/3.
//

#include <iostream>
#include <memory>


using namespace std;

int main(){
    // shared ptr
    // 创建
    // 空的 shared_ptr 指针，其初始引用计数为 0，而不是 1。
    shared_ptr<int> p_1;
    shared_ptr<int> p_2(nullptr);  // 构造函数初始化

    // 创建时明确指向的对象 下面两个是一样的
    shared_ptr<int> p_3(new int (1));
    shared_ptr<int> p_4 = make_shared<int>(1);  // 使用make_shared
    cout << p_3 << endl;

    // 使用拷贝构造函数 进行初始化
    shared_ptr<int> p_5(p_4);
    // 移动构造函数

    return 0;
}