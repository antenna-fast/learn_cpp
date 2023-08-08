// multi-threads can read a variable at one time 
// BUT can NOT write it at one time

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    if(argc != 1){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    return 0;
}