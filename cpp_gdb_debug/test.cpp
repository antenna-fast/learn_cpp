#include <iostream>

using namespace std;

int main(int argc, char** argv){
    if(argc != 2){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    cout << "line: " << 1 << endl;
    cout << "line: " << 2 << endl;
    cout << "line: " << 3 << endl;
        
    return 0;
}
