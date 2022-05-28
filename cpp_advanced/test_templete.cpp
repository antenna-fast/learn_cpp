//
// Created by yaohua on 2022/4/29.
//

#include <iostream>

using namespace std;

// 函数模板
// swap函数
template<typename T> void Swap(T *a, T *b){
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template<typename T>
inline T const& Max(T const &a, T const &b){
    return a < b ? b : a;
}


// 类模板
template<typename T1, typename T2>
class Point{
public:
    // 特殊成员函数
    // 构造函数
    Point(T1 t_x, T2 t_y):x(t_x), y(t_y){}

    // 普通成员函数
    void SetXY(T1 t_x, T2 t_y);
private:
    T1 x;
    T2 y;
};

// 定义成员函数的时候，base-class后面也要<T1, T2>，只不过不需要typename了
template<typename T1, typename T2>
void Point<T1, T2>::SetXY(T1 t_x, T2 t_y) {
    x = t_x;
    y = t_y;
}

int main(){
    // test function 1
    string str_var_1 = "antenna";
    string str_var_2 = "fast";
    Swap(&str_var_1, &str_var_2);
    cout << "var_1: " << str_var_1 << "  str_var_2: " << str_var_2 << endl;

    // test function 2
    int a = 10;
    int b = 20;
    int c = Max(a, b);
    cout << "c: " << c << endl;

    double e = 12.34;
    double f = 56.78;
    double g = Max(e, f);
    cout << "g: " << g << endl;

    // 类模板
    // 实例化1
    Point<int, int> point_1(10, 10);
    point_1.SetXY(20, 20);
    // 实例化2
    Point<double, int> point_2(10.2, 10);

    // 使用对象指针
    auto *p_1 = new Point<int, int>(1, 1);
    p_1 ->SetXY(2, 2);

    return 0;
}