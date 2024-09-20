#include <iostream>
#include <stdio.h>
#include <boost/bind.hpp>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

int add3(int a, int b, int c)
{
    return a + b + c;
}

int main(int argc, char **argv) 
{
    // simple case
    // int r = boost::bind(add, 1, 2)();  // this is equal to 

    // selectively bind
    // _1, _2 ... is index corresponding to the following parameter list
    int r = boost::bind(add3, _1, _1, _2)(5, 2);  // _1: 5, _2: 2

    int r2 = boost::bind(add3, _2, _1, _2)(5, 2);  // _1: 5, _2: 2

    cout << "r: " << r << endl;  // got 12
    cout << "r2: " << r2 << endl;  // got 9

}
