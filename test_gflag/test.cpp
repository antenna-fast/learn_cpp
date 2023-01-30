#include <iostream>

#include "gflags/gflags.h"

DEFINE_bool(a, true, "test bool");
DEFINE_string(b, "hehe", "test string");

using namespace std;

int main(int argc, char** argv){
    // if(argc != 1){
    //     cout << " argc not match, Usage: " << endl;
    //     return -1;
    // }

    std::cout << "running: " << argv[0] << std::endl;
    
    google::ParseCommandLineFlags(&argc, &argv, true);

    std::cout << "a: " << FLAGS_a << std::endl;
    std::cout << "b: " << FLAGS_b << std::endl;

    return 0;
}