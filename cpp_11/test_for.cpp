//
// Created by yaohua on 2022/5/7.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a;
    cout << "push_back " << endl;
    for (int i = 0; i < 10; ++i) {
        a.push_back(i);
    }

    cout << "auto: " << endl;
    for (auto x:a) {
        cout << "x: " << x << endl;
    }
    
    // iter
    auto a_iter = a.begin();
    while (a_iter != a.end()) {
        cout << "aIter: " << *a_iter << endl;
        a_iter ++;
    }
    return 0;
}
