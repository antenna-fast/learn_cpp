//
// Created by yaohua on 2022/5/14.
//

#include <iostream>
#include <list>
#include <stack>

using namespace std;


int main(){

    list<int> vals{1,2,3,4};  // 底层采用 deque 基础容器的 stack 适配器
    stack<int, list<int>> stack_1(vals);
    stack_1.push(1);

    while (!stack_1.empty()){
        cout << "stack: " << stack_1.top() << endl;
        stack_1.pop();
    }

    return 0;
}