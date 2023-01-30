//
// Created by yaohua on 2022/4/28.
//

#include <iostream>

using namespace std;

// 函数重载
class PrintOverride{
public:
    void print(int i){
        cout << "output int: " << i << endl;
    }
    void print(string i){
        cout << "output string: " << i << endl;
    }
    void print(double i){
        cout << "output double: " << i << endl;
    }
};


// operator overload

// functor: 重载() operator
struct add_x{
    // construct function 
    // 给成员变量赋值
    explicit add_x(int val):x(val){}  

    int operator()(int y) const {return x+y;}   // 重载() operator

private:
    int x;
};


int main(){

    int a = 1;
    double b = 6.66;
    string c = "1";

    PrintOverride po;
    po.print(a);
    po.print(b);
    po.print(c);

    // test functor
    add_x add_99(99);  // 实例化
    int res = add_99(81);
    cout << "res: " << res << endl;

    return 0;
}