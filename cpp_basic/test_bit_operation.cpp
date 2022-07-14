//
// Created by yaohua on 2022/5/6.
//

#include <iostream>


using namespace std;

int main(){

    unsigned int a = 2;
    unsigned int b = 3;
    // 异或
    cout << (a ^ b) << endl;
    // 
    cout << (a & b) << endl;
    cout << (a | b) << endl;
    cout << (~a) << endl;

    cout << (a << 1) << endl;
    cout << (a >> 1) << endl;

    return 0;
}
