//
// Created by yaohua on 2022/4/30.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;


bool void_test(int s){
    return s != 0;
}

int main(){
    cout << "STL test .. " << endl;
    vector<int> vec_1;
    cout << "size of vector: " << vec_1.size() << endl;

    const int vec_length = 10;

    // push value to vectoe
//    for (int i = 0; i < 5; ++i) {
    for (int i = 0; i < vec_length; i++) {
        vec_1.push_back(i);
    }
    cout << "size of vector: " << vec_1.size() << endl;
    cout << "capaticity of vector: " << vec_1.capacity() << endl;

    // get value of vector
    for (int j = 0; j < vec_length; ++j) {
        cout << "value of vec_1 in " << j << ": " << vec_1[j] << endl;
    }

    // using iterator 迭代器
    cout << "using iterator " << endl;
    // vector<int>::iterator v = vec_1.begin();
    auto v = vec_1.begin();
    while (v != vec_1.end()){
        cout << "value: " << *v << endl;
        v++;
    }

    vec_1.push_back(1);
    vec_1.push_back(2);
    sort(vec_1.begin(), vec_1.end());
    auto res = unique(vec_1.begin(), vec_1.end());  // 把后面不重复的移动到前面，并没有改变长度

    auto s = vec_1.begin();
    while (s != vec_1.end()){
        cout << *s << endl;
        s ++;
    }

    cout << (res != vec_1.end()) << endl;

    // vector to set
    set<int> a(vec_1.begin(), vec_1.end());
    auto a_iter = a.begin();
    while (a_iter != a.end()){
        cout << "set: " << *a_iter << endl;
        a_iter ++;
    }

    string ss = "12344";
    cout << "hhh: " << ss[2] << "  " << ss.size() << endl;

    // lambda


    cout << "count if: " << count_if(vec_1.begin(), vec_1.end(), void_test) << endl;

    // 生成随机数
    vector<int> var_rand(100);
    generate(var_rand.begin(), var_rand.end(), rand);


    return 0;
}
