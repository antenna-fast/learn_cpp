//
// Created by yaohua on 2022/5/12.
//

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;


int main(){
    
    set<string> set_1 = {"123", "456", "789"};  // 初始化构造函数
    set_1.insert("666");
    
    // copy constructor 
    set<string> set_2(set_1);
    cout << "set 2 size: " << set_2.size() << endl;

    // iter on set1
    auto iter_set_1 = set_1.begin();
    while (iter_set_1 != set_1.end()){
        cout << "iter: " << *iter_set_1 << endl;
        iter_set_1 ++;
    }
    cout << "set 1 size: " << set_1.size() << endl;

    // delete set element
    set_1.erase("666");
    cout << "set 1 size after: " << set_1.size() << endl;

    // iter on set1
    iter_set_1 = set_1.begin();
    while (iter_set_1 != set_1.end()){
        cout << "after erase iter: " << *iter_set_1 << endl;
        iter_set_1 ++;
    }

    // copy 1 to 2 
    // set<string> set_2; 
    // set_2 = set_1;
    cout << "set 2 size: " << set_2.size() << endl;

    // iter on set2
    auto iter_set_2 = set_2.begin();
    while (iter_set_2 != set_2.end()){
        cout << "iter2: " << *iter_set_2 << endl;
        iter_set_2 ++;
    }

    cout << endl;
    // intersection of two set
    set<string> intersect_buffer;
    set_intersection(set_1.begin(), set_1.end(),
                    set_2.begin(), set_2.end(),
                    std::inserter(intersect_buffer, intersect_buffer.begin()));
    auto iter_set_3 = intersect_buffer.begin();
    while (iter_set_3 != intersect_buffer.end()){
        cout << "iter3: " << *iter_set_3 << endl;
        iter_set_3 ++;
    }


    // find element in set

    return 0;
}