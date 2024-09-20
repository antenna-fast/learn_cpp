//
// Created by yaohua on 2022/4/28.
//

#include <iostream>
#include <vector>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>


using namespace std;

class Point3D {
public:
    double x;
    double y;
    double z;

    // constructor with parameters
    Point3D(double t_x, double t_y, int t_z):x(t_x), y(t_y), z(t_z)
    {
        num_points ++;
    }

    // copy constructor (will be generated automticaly by compiler)
    // if we hand-write it, will perform this
    Point3D(const Point3D& p) 
    {
        x = p.x;
        y = p.y;
        z = p.z;
        num_points ++;
    }

    void get() const;

    static size_t getCount();

    // friend member function
    friend void printVar(Point3D point3d);

// private方法: 不需要用户知道的实现细节
private:
    // 类的静态成员:
    // 在类定义中, 关键字 static 声明未绑定到类实例的成员。
    // 静态成员在类的所有对象中是共享的。如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。
    // 我们不能把静态成员的初始化放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化
    static size_t num_points;

    // 静态成员函数: 
    // 如果把函数成员声明为静态的，就可以把函数与类的任何特定对象独立开来。
    // 静态成员函数即使在类对象不存在的情况下也能被调用，静态函数只要使用类名加范围解析运算符 :: 就可以访问。
    // 静态成员函数只能访问静态成员数据、其他静态成员函数和类外部的其他函数。
    // 静态成员函数有一个类范围，他们不能访问类的 this 指针。您可以使用静态成员函数来判断类的某些对象是否已被创建。

};
/// end of class Point3D

// init static member in class: note: no static indicator
size_t Point3D::num_points = 0;

size_t Point3D::getCount()
{
    return num_points;
}


// 成员函数定义
void Point3D::get() const
{
    cout << "x: " << x << "  y: " << y << "  z: " << z << endl;
}

// 友元函数定义
// 类的友元，提供了类成员的访问权限
void printVar(Point3D point3d)
{
    cout << "a: " << point3d.z << endl;
}


int main()
{
    Point3D point_1(1, 2, 2);
    Point3D point_2(3, 4, 5);

    // test copy constructor
    Point3D point_3(point_2);  // use 复制构造函数
    point_3.get();  // 成员变量的数值都被复制了过来

    // static member function test: we do not need to using instance to call this
    cout << "Total points: " << Point3D::getCount() << endl;

    // test friend function
    printVar(point_3);

    return 0;
}
