//
// Created by yaohua on 2022/4/27.
//

#include <iostream>
#include <ctime>

using namespace std;

int main(){

    time_t now = time(0);
    cout << "now: " << now << endl;

    char *dt = ctime(&now);
    cout << "dt: " << dt << endl;

    return 0;
}