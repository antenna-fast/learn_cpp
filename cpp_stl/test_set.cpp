//
// Created by yaohua on 2022/5/12.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;


int main(){
    set<string> set_1 = {"123", "456", "789"};  // 初始化构造函数
    set_1.insert("666");
    // 遍历set
    auto iter_set_1 = set_1.begin();
    while (iter_set_1 != set_1.end()){
        cout << *iter_set_1 << endl;
        iter_set_1 ++;
    }

    // 删除set的元素
    
    return 0;
}