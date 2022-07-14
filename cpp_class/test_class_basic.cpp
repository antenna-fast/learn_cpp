//
// Created by yaohua on 2022/4/28.
//

#include <iostream>

using namespace std;

// 最基本语法
// class 关键字
// 类名
class Point3D {
// 访问标志符:
// 变量;
// 方法;

// 变量
public:
    double x;
    double y;

private:
    int a;

// 方法, 成员函数
public:
    // 构造函数
    Point3D(double t_x, double t_y, int t_a):x(t_x), y(t_y), a(t_a){}

    void get() const;

    // 友元函数
    friend void printVar(Point3D point3d);
};  // 有分号

// 成员函数定义
void Point3D::get() const {
    cout << "x: " << x << "  y: " << y << endl;
}

// 友元函数定义
void printVar(Point3D point3d){
    // 类的友元，提供了类成员的访问权限
    cout << "a: " << point3d.a << endl;
}


int main(){
    Point3D point_1(1,2, 2);
    Point3D point_2(3,4, 5);

    Point3D point_3(point_2);  // 默认复制构造函数
    point_3.get();  // 成员变量的数值都被复制了过来

    // 友元函数
    printVar(point_3);

    return 0;
}
