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

template <typename T>
void print_vector(const vector<T> &input_vector){
    for (size_t i = 0, length = input_vector.size(); i < length; i++){
        cout << "element " << i << ": " << input_vector[i] << endl;
    }
    return;
}

int main(){
    std::cout << "STL test" << endl;

    vector<float> vf(42709547);

    // vector的初始化
    // 不使用(空)构造函数
    vector<int> vec_1;
    std::cout << "size of vec_1: " << vec_1.size() << endl;
    
    // 构造函数 (元素个数)
    vector<int> vec_2(4);
    std::cout << "size of vec_2: " << vec_2.size() << endl;
    // print_vector(vec_2);

    // 构造函数 (元素个数, 元素数值)
    vector<int> vec_3(3, 888);
    std::cout << "size of vec_3: " << vec_3.size() << endl; 
    print_vector(vec_3);

    // 动态添加元素
    // push value to vector
    const int vec_length = 10;
    for (int i = 0; i < vec_length; i++) {
        vec_1.emplace_back(i);
    }
    // 查看元素个数
    std::cout << "size of vector: " << vec_1.size() << endl;
    // 查看容量
    std::cout << "capacity of vector: " << vec_1.capacity() << endl;  

    // get value of vector
    for (int j = 0; j < vec_length; ++j) {
        std::cout << "value of vec_1 in " << j << ": " << vec_1[j] << endl;
    }

    // using iterator 迭代器
    std::cout << "using iterator " << endl;
    // vector<int>::iterator v = vec_1.begin();
    auto v = vec_1.begin();
    while (v != vec_1.end()){
        std::cout << "value: " << *v << endl;
        v++;
    }

    vec_1.push_back(1);
    vec_1.push_back(2);
    std::sort(vec_1.begin(), vec_1.end());
    auto res = unique(vec_1.begin(), vec_1.end());  // 把后面不重复的移动到前面，并没有改变长度

    auto s = vec_1.begin();
    while (s != vec_1.end()){
        cout << *s << endl;
        s ++;
    }

    cout << (res != vec_1.end()) << endl;

    // vector to set
    set<int> a(vec_1.begin(), vec_1.end());  // set的构造函数
    // iter the set
    auto a_iter = a.begin();
    while (a_iter != a.end()){
        cout << "set: " << *a_iter << endl;
        a_iter ++;
    }

    string ss = "12344";
    cout << "hhh: " << ss[2] << "  " << ss.size() << endl;

    // lambda[??]
    cout << "count if: " << count_if(vec_1.begin(), vec_1.end(), void_test) << endl;

    // fill: 用value填充vector
    std::fill(vec_1.begin(), vec_1.end(), -1);
    print_vector(vec_1);

    // 生成随机数
    vector<int> var_rand(100);
    generate(var_rand.begin(), var_rand.end(), rand);

    return 0;
}
