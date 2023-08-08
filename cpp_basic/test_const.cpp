// demo of const data type
// ref: https://blog.csdn.net/luoweifu/article/details/45600415

#include <iostream>

using namespace std;


int main(int argc, char** argv){
    if(argc != 1){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;

    // demo1: const T
    // const int a;     // error, need to init when define 
    const int b = 0;    // ok
    // b = 3;       // error, can not modify value

    // demo2: const T*
    // Can modify ptr itself
    // can Not modify ptr->value
    const int* c = &b;
    // *c = 2;      // error, can not modify const ptr's value 
    int d = 1;
    c = &d;     // ok, you can modify the ptr itself
    cout << "*c: " << *c << endl;

    // demo3: T* const
    // const ptr
    // Can modify modify its->value
    // can Not modify itself
    int* const e = &d;
    int f = 2;
    // e = &f; // error, can not modify ptr itself 
    *e = 3; // ok, you can modify the value of this ptr

    // demo4: const T* const
    const int* const g = &b;


    // demo5: const T& 
    const int& h = b;  // const reference of b
    // h = 0;  // error, can not be modified

    return 0;
}