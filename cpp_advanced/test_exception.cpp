//
// Created by yaohua on 2022/4/29.
// exception
// 

#include <iostream>

using namespace std;

enum {
    A,
    B,
    C
};

int main(){

    int e_type = A;

    try{
        if(e_type == A){
            throw "ERROR A";
        }
    }
    catch(const char *msg){
        cerr << msg << endl;
    }

    return 0;
}
