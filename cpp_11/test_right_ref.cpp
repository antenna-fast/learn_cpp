// lvalue: locator value, in memory, can be locate address
// rvalue: read value, may not be locate address, eg. in register, 

// 右值引用主要用于移动语义和完美转发

// http://c.biancheng.net/view/7829.html


#include <iostream>

using namespace std;

int main()
{
    cout << "test right reference" << endl;

    int i = 5;  // the i is lvalue, the "5" is rvalue 
    // 5 = i;   // error
    int j = i;  // ok, the lvalue can as a rvalue

    // get the address of lvalue 
    cout << "get address: &i: " << &i << " &j: " << &j << endl;
    
    // reference
    int &k = i;  // ok
    // int &k = 10;  // error

    // const reference
    int num = 10; 
    const int &b = num; // ok
    const int &c = 10;  // ok

    // rvalue 
    int && a = 123;
    a = 321;  // modify rvalue, ok

    const int&& c = 123; 

    return 0;
}