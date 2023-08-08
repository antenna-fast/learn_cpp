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

enum Stage {
    STAGE_PAUSED,
    STAGE_FIRST_FRAME,
    STAGE_SECOND_FRAME,
    STAGE_DEFAULT_FRAME,
    STAGE_RELOCALIZING
};


int main()
{
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    eTrackingState mState;
    cout << mState << endl;

    Stage s;
    s = STAGE_RELOCALIZING;
    cout << "s: " << s << endl;

    return 0;
}