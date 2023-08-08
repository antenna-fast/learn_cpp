#include <iostream>
#include <assert.h>


using namespace std;

int main(int argc, char** argv) {
    if(argc != 1){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    int a = 1;
    assert(a == 1);  // ok
    assert(a != 1);  // not ok

    return 0;
}