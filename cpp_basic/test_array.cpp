//
// Created by yaohua on 2022/4/27.
//

#include <iostream>


using namespace std;

int main(int argc, char** argv){
    cout << "running: " << argv[0] << endl;

    // declaration a array:
    // data_type var_name[num_of_element]
    int a[3];
    cout << "a: " << a << endl;

    // declaration with init
    int b[] = {1, 2, 3};

    // get element of array
    int c = a[0];
    
    return 1;
}
