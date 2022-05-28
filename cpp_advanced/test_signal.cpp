//
// Created by yaohua on 2022/4/30.
//

#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;


void signalHandler(int signum){
    cout << "Interrupt signal :" << signum << endl;
    exit(signum);
}

int main(){
    cout << "test signal. " << endl;
    signal(SIGINT, signalHandler);

    int i = 0;

    while (1){
        cout << "running ... " << endl;
        sleep(1);
        i++;

        if (i >= 3)
            raise(SIGINT);
    }
    return 0;
}