//
// Created by yaohua on 2022/4/28.
//

#include <iostream>
#include <vector>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>


using namespace std;

// class basic

class Point3D {
// public var
public:
    double x;
    double y;

// private var
private:
    int a;

    static size_t num_points;

// public member function: user interface
public:  
    // constructor with parameters
    Point3D(double t_x, double t_y, int t_a):x(t_x), y(t_y), a(t_a)
        {
            num_points ++;
        }

    // copy constructor (will be generated automticaly by compiler)
    // if we hand-write it, will perform this
    Point3D(const Point3D& p) {
        x = p.x;
        y = p.y;

        a = p.a;

        num_points ++;
    }

    void get() const;

    static size_t getTotal();

    // friend member function
    friend void printVar(Point3D point3d);

// private方法: 不需要用户知道的实现细节

};
/// end of class Point3D

size_t Point3D::num_points = 0;

size_t Point3D::getTotal()
{
    return num_points;
}


// 成员函数定义
void Point3D::get() const {
    cout << "x: " << x << "  y: " << y << endl;
}

// 友元函数定义
// 类的友元，提供了类成员的访问权限
void printVar(Point3D point3d){
    cout << "a: " << point3d.a << endl;
}


int main(){
    Point3D point_1(1, 2, 2);
    Point3D point_2(3, 4, 5);

    // test copy constructor
    Point3D point_3(point_2);  // use 复制构造函数
    point_3.get();  // 成员变量的数值都被复制了过来

    cout << "Total points: " << Point3D::getTotal() << endl;

    // test friend function
    printVar(point_3);

    return 0;
}
