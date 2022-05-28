//
// Created by yaohua on 2022/5/7.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> a;
    a.reserve(10);
    for (int i = 0; i < 10; ++i) {
        a.push_back(i);
    }

    for (auto x:a){
        cout << "a: " << x << endl;
    }

    // iter
    auto a_iter = a.begin();
    while (a_iter != a.end()){
        cout << "aIter: " << *a_iter << endl;
        a_iter ++;
    }
    return 0;
}