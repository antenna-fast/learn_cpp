//
// Created by yaohua on 2022/4/29.
//

#include <iostream>

using namespace std;

namespace first_namespace{
    void PrintTest(string a){
        cout << "first_namespace: " << a << endl;
    }
}

namespace second_namespace{
    void PrintTest(string a){
        cout << "second_namespace: " << a << endl;
    }
}

int main(){
    first_namespace::PrintTest("123");
    second_namespace::PrintTest("456");

}
