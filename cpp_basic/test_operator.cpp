/*
操作符
*/

#include <iostream>

using namespace std;


int main(){

    // C风格
    double x = 2.998;
    int y = (int) x;
    cout << "y: " << y << endl;

    // C++风格

    // static_cast 
    // 使用static_cast可以明确告诉编译器，这种损失精度的转换是在知情的情况下进行的，
    // 也可以让阅读程序的其他程序员明确你转换的目的而不是由于疏忽。
    double a = 1.999;
    int b = static_cast<double>(a);

    cout << "b: " << b <<endl;

    int c = a;
    cout << "c: " << c << endl;

    return 0;
}