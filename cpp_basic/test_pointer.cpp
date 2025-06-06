//
// Created by yaohua on 2022/4/27.
//

#include <iostream>


using namespace std;


// 数组指针 
void arr_pointer()
{
    int a[4] = {1,2,3,4};  // a是数组名，指向数组的第0个元素，表示数组的首地址
    // a = {5, 6, 7, 8};  // 数组名是常量，不可以被改变

    // 求数组的长度
    int len_arr = sizeof(a) / sizeof(int);

    // 数组指针，指针指向了数组
    // 指针变量pa指向数组a的首地址  数组变量名a被转换成了一个指针
    int (*pa) = a;  // 指针变量，可以改变
    // 等价于
    // pa = &a[0];

    // 使用指针访问数组
    // pa为数组首地址
    // +1为偏移量
    // * 取出偏移后的指针的值
    for (size_t i = 0; i < len_arr; i++)
    {
        cout << *(pa + i) << " ";  // 指针访问
        cout << a[i] << " " << endl;  // 下标访问
    } 
    cout << endl;

    return;
}


// 普通指针，指向数组首元素
void arr_pointer1()
{
    int numElements = 10;
    // 动态分配内存
    float *pA = (float *)malloc(numElements * sizeof(float));

    // 给数组赋值
    for (size_t i = 0; i < numElements; i++)
    {
        pA[i] = i;
    }
    
    // 打印数组
    for (size_t i = 0; i < numElements; i++)
    {
        cout << pA[i] << " ";;
    }
    cout << endl;
    return;
}


int b = 998;

// void change_val(int* &a)  // right  a: 指针的引用, ok
void change_val(int* a)  
{
    a = &b;  // wrong, it will not work, because this operation only change pointer's position
    // *a = 100;
} 

int main()
{
    cout << "pointer test " << endl;

    // arr_pointer();
    
    int a = 10;
    int *b = &a; // b: 指针变量
    *b = 20;

    std::cout << "b: " << b << " *b: " << *b << "  a: " << a << std::endl;

    // 取地址&操作符
    int var_1 = 0;
    int var_2[10];
    
    cout << "position of var_1: " << &var_1 << endl;
    cout << "position of var_2: " << &var_2 << endl;
    
    int var_3 = 666;
    int *p_var_1;  
    p_var_1 = &var_3;

    cout << "var_3: " << var_3
        << " p_var: " << p_var_1
        << " v_p_var: " << *p_var_1 << endl;

    cout << "var_1 :" << var_1 << endl;
    cout << "var_3: " << var_3 << endl;

    int *p_var_8 = &var_1;
    int *p_var_9 = p_var_8;
    p_var_9 = &var_3;
    cout << "p_var_8: " << *p_var_8 << endl;

    // test pointer function
    int var_no_p;
    // change_val(&var_no_p);
    // cout << "var_no_p: " << var_no_p << endl;

    int *var=&var_no_p;
    change_val(var);
    cout << "var after change_val: " << *var << endl;
    

    // int* &  指针的引用
    // ref: https://blog.csdn.net/fatfish_/article/details/86768887

    int* & var_1p = p_var_1;
    cout << "var_1p: " << var_1p << endl;
    cout << "var_1p: " << *var_1p << endl;

    int *d = nullptr;
    int * &dp = d;
    

    int c = 9;    
    var_1p = &c;
    cout << "var_1p: " << *var_1p << endl;

    // 引用并不存在地址
    // int ri=0;
    // int &*p = &ri;  // wrong operation

    return 0;
}
