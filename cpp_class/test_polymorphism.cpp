//
// Created by yaohua on 2022/4/29.
//

// test ploymorphism
// 使用相同的函数名，分别求矩形和三角形的面积

#include <iostream>

using namespace std;


// base-class
class Shape{
protected:
    double width;
    double height;

public:
    void setWH(double t_width, double t_height);
    // 虚函数
    virtual double getArea(){
        cout << "getArea in base-class ... " << endl;
        return 0;
    };
    // 纯虚函数：=0, 没有函数主体
//    virtual double getArea()=0;
};

void Shape::setWH(double t_width, double t_height) {
    width = t_width;
    height = t_height;
}

// derivation-class: Rectangle
class Rectangle : public Shape{
public:
    double getArea();
};

double Rectangle::getArea() {
    return width * height;
}


// derivation-class: Triangle
class Triangle : public Shape{
public:
    double getArea();
};

double Triangle::getArea() {
    return 0.5 * width * height;
}

int main(){
    // 以下，正确执行多态
    Rectangle rect_1;
    rect_1.setWH(10, 10);
    double rect_area_1 = rect_1.getArea();
    cout << "rect_area_1: " << rect_area_1 << endl;

    Triangle tria_1;
    tria_1.setWH(10, 10);
    double tria_area_1 = tria_1.getArea();
    cout << "tria_area_1: " << tria_area_1 << endl;

    // 以下，执行的base-class 中的getArea
    // 如果Shape中的getArea没有加virtual, 则早绑定，静态多态，静态连接
    Shape *shape;
    shape = &rect_1;
    cout << "shape_rect_1: " << shape->getArea() << endl;

    shape = &tria_1;
    cout << "shape_tria_1: " << shape->getArea() << endl;

    return 0;
}
