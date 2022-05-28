//
// Created by yaohua on 2022/5/12.
//

#include <iostream>
#include <utility>  // for pair
#include <string>

using namespace std;


int main(){
    // 1. 调用默认构造函数
    pair<string, double> pair_1;

    // 2. 直接使用元素初始化对象
    pair<string, string> pair_2("123", "456");

    // 3. 拷贝构造函数
    pair<string, string> pair_3(pair_2);

    // 4. 移动构造函数
    // pair<string, string> pair_4(make_pair("666", "999"));
    // 等价写法
    pair<string, string> pair_4 = make_pair("666", "999");

    // 5. 右值引用
    pair<string, string> pair_5(string("99"), string("81"));

    // 访问元素
    cout << "first: " << pair_1.first << "  second: " << pair_1.second << endl;
    cout << "first: " << pair_2.first << "  second: " << pair_2.second << endl;
    cout << "first: " << pair_3.first << "  second: " << pair_3.second << endl;
    cout << "first: " << pair_4.first << "  second: " << pair_4.second << endl;
    cout << "first: " << pair_5.first << "  second: " << pair_5.second << endl;

    return 0;
}