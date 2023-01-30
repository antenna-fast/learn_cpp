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
// access signature: public, private

// Variable
// public var
public:
    double x;
    double y;

// private var
private:
    int a;

// Member Function
// public member function: user interface
public:  
    // constructor

    // constructor with parameters
    Point3D(double t_x, double t_y, int t_a):x(t_x), y(t_y), a(t_a){}

    // copy constructor (will be generated automticaly by compiler)
    // if we hand-write it, will perform this
    Point3D(const Point3D& p) {
        x = p.x;
        y = p.y;

        a = p.a;
    }

    void get() const;

    // friend member function
    friend void printVar(Point3D point3d);

// private方法: 不需要用户知道的实现细节

};
/// end of class Point3D


// 成员函数定义
void Point3D::get() const {
    cout << "x: " << x << "  y: " << y << endl;
}

// 友元函数定义
// 类的友元，提供了类成员的访问权限
void printVar(Point3D point3d){
    cout << "a: " << point3d.a << endl;
}


/// Disable copy constructor
class Frame
{
public:
    Frame() {};
    // delete copy constructor
    Frame(const Frame& ) = delete;
    
    // delete = operator
    Frame& operator = (const Frame&) = delete;


private:
    
};


class Map : boost::noncopyable
{
public:
    Map() {};

    vector<Point3D> points;
    vector<Frame> keyFrames;
    
private:

};


// test singleton mode
class Tracker
{
public:
    Tracker(){}
    Tracker(int a) { x = a;}
    ~Tracker(){}

    static Tracker* getInstance()
    {
        if(instance == NULL)
        {
            instance = new Tracker();
        }
        return instance;
    }

    int x;

private:
    static Tracker* instance;

};


Tracker* Tracker::instance = NULL;

int main(){
    Point3D point_1(1, 2, 2);
    Point3D point_2(3, 4, 5);

    // test copy constructor
    Point3D point_3(point_2);  // use 复制构造函数
    point_3.get();  // 成员变量的数值都被复制了过来

    // test delete copy constructor and = operator 
    Frame a;
    // Frame b(a);  // error
    // Frame c = a; // error

    Map map;
    // Map map2(map);  // error
    // Map map3 = map; // error

    typedef boost::shared_ptr<Frame> FramePtr;

    FramePtr frame_1;
    FramePtr frame_2(frame_1);  // ok!
    FramePtr frame_3 = frame_1; // ok!


    // test default constructor 
    // Tracker tracker_1(1);
    // cout << "tracker_1.x: " << tracker_1.x << endl;

    // test singleton mode
    // yes, you will see that, *p_tracker_1 = *p_tracker_2
    Tracker *p_tracker_1 = Tracker::getInstance();
    cout << "p_tracker_1: " << p_tracker_1 << endl;

    Tracker *p_tracker_2 = Tracker::getInstance();
    cout << "p_tracker_2: " << p_tracker_2 << endl;

    // test friend function
    printVar(point_3);

    return 0;
}
