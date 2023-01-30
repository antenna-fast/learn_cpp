//
// Created by yaohua on 2022/4/28.
//

#include <iostream>

using namespace std;

// 继承 inheritance

// base-class
class Animal{
public:
    string name;
    int age;
    double height;
    string color;

    // const int a;      // not ok: 常量的成员，必须使用初始化列表显示初始化（或者直接固定住）
    // const int a=1;    // ok: 常量的成员，必须使用初始化列表显示初始化（或者直接固定住）

public:
    // 构造函数1
    // override
    Animal();  // 构造函数声明  无参构造函数

    // 构造函数声明2 
    // 初始化列表 有参构造函数
    Animal(string name_):name(name_){}; 
    
    // 构造函数声明3
    // 构造函数名(参数表):成员变量(对应的参数列表中的参数名), ... {}
    Animal(string name_, int age_, double height_) : name(name_), age(age_), height(height_){};

    void show();
};

// base-class 构造函数
// 初始化成员变量
// 无参构造函数
Animal::Animal(){
    height = 0;
    age = 1;
}

// 有参构造函数
// 此时会和初始化列表的redefination, 因为他们的参数列表相同
//Animal::Animal(int t_age, double t_height){
//    age = t_age;
//    height = t_height;
//}

void Animal::show() {
    cout << "name: " << name << endl << "age: " << age << endl << "height: " << height << endl << endl;
}

// derivation-class 派生类
// access indicator:
// public：不改变基类的成员变量访问标志
// private/protected will 将基类的标志变为private/protected

class Dog : public Animal{
    public:
    Dog();

    string type;
};

// init base class when buils constructor
Dog::Dog():Animal("1234", 9, 9)  
{

}

class Cat: public Animal{
    string type;

};



int main(){

    // 构造函数的不同初始化方式
    Animal animal_0;
    cout << "animal_0: " << endl;
    animal_0.show();

    cout << "animal_1" << endl;
    Animal animal_1("1");
    animal_1.show();

    cout << "dog_1:" << endl;
    Dog dog_1;
    dog_1.show();

    return 0;
}
