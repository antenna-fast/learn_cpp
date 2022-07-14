//
// Created by yaohua on 2022/4/26.
//

#include <iostream>


using namespace std;


enum int_enum{
    a,
    b,
    c
} d;


// 尽管有-1的，但是默认值是0
enum eTrackingState{
    SYSTEM_NOT_READY=-1,
    NO_IMAGES_YET=0,
    NOT_INITIALIZED=1,
    OK=2,
    LOST=3
};


int main()
{
    cout << "Hello! " << a << endl;
    cout << "Hello! " << b << endl;
    cout << "Hello! " << c << endl;

    eTrackingState mState;
    cout << mState << endl;

    return 0;
}