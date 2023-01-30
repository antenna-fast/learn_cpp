// Created by yaohua on 2022/4/27.


#include <iostream>
#include <typeinfo>

using namespace std;

// 函数的参数

// 引用传递
void test_double(int &a){
    a = 2 * a;  // 改变形参的value，就会改变实参的value
}

void test_swap(int &a, int &b){  // 参数表需要指明&
    int tmp = a;  // 函数内部操作，不需要*
    a = b;
    b = tmp;
}

// 指针传递
void test_pointer(int *a){  // 参数表需要指明*
    *a = *a + 1;  // 函数内部操作，需要显式取值*
}

// 函数内部新建了地址变量
// 对地址变量指向的内容进行操作
// 和p的含义一样，所以，pp变量无意义
void test_pointer(double *p){
    double *pp = p;
    *pp += 999;
    // *p += 999;
}

// function template
template<class T>
T add_1(T a){  // return_type, func_name(parameter list)
    return a + 1;
}

template<typename T>
void hello_T(const T& var_in){
    std::cout << "from hello_T: hello, " << var_in << " typeinfo: " << typeid(var_in).name() << std::endl; 

}

// 函数指针
// 普通函数
int fun_add(int a, int b){
    return a + b;
}
// 函数指针
// 其中，p_fun_add是一个指针函数名，后面的是参数列表
int (*p_fun_add) (int, int) = fun_add;


int main(){

    // 值传递 略

    // 引用传递测试
    // demo 1
    int a = 1;
    test_double(a);
    cout << "after double: " << a << endl;

    // demo 2
    int x = 10;
    int y = 20;

    test_swap(x, y);  // 给定的时候不需要&
    cout << "after swap " << "x: " << x << "  y: " << y << endl;

    // 指针传递
    int z = 88;
    test_pointer(&z);  // 给定的时候，需要&取地址，或者直接给定指针变量
    cout << "after pointer: " << z << endl;

    double dd = 123;
    test_pointer(&dd);
    cout << dd << endl;

    // Template Function
    cout << "函数模板" << endl;
    int aa = 1;
    cout << add_1(aa) << endl;

    double bb = 1;
    cout << add_1(bb) << endl;

    const int x_1 = 1;
    cout << add_1(x_1) << endl;

    hello_T("123");

    int b = 123;
    hello_T(b);

    // Pointer Function
    cout << "函数指针 p_fun_add: " << (*p_fun_add)(3, 4) << endl;

    // inline 内联函数
    
    return 0;
}