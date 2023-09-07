#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// ref: https://nettee.github.io/posts/2018/Understanding-lvalues-and-rvalues-in-C-and-C/
// 左值 (lvalue, locator value) 表示了一个占据内存中某个可识别的位置（也就是一个地址）的对象。
// 右值 (rvalue) 是一个 不表示内存中某个可识别位置的对象的表达式。

int global_var = 10;

// 这里 foo 返回一个引用。引用一个左值
int& foo() 
{
    return global_var;
}

// not a reference, return right value
int bar() 
{
    return global_var;
}


int main()
{
    foo() = 2; // right 
    // bar() = 1; // error
    std::cout << "global_var: " << global_var << endl;

    // var 是一个有内存位置的对象，因此它是左值
    int var;
    var = 4;

    // 常量 4 和表达式 var + 1 都不是左值（也就是说，它们是右值），因为它们都是表达式的临时结果，而没有可识别的内存位置
    // 4 = var;       // 错误！
    // (var + 1) = 4; // 错误！


    const int a = 10; // 'a' 是左值
    // a = 10;           // 但不可以赋值给它！


    // cpp reference
    std::string str = "Salut";
    std::vector<std::string> v;
 
    // uses the push_back(const T&) overload, which means 
    // we'll incur the cost of copying str
    v.push_back(str);
    std::cout << "After copy, str is " << std::quoted(str) << '\n';
 
    // uses the rvalue reference push_back(T&&) overload, 
    // which means no strings will be copied; instead, the contents
    // of str will be moved into the vector. This is less
    // expensive, but also means str might now be empty.
    v.push_back(std::move(str));
    std::cout << "After move, str is " << std::quoted(str) << '\n';
    
    // string aa= "hhhh";
    // std::cout << aa << std::quoted(aa) << std::endl;

    std::cout << "v_size: " << v.size() << std::endl;
    std::cout << "The contents of the vector are { " << std::quoted(v[0])
              << ", " << std::quoted(v[1]) << " }\n";

    return 0;
}

