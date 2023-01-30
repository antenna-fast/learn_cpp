#include <iostream>

using namespace std;


template<typename ...T>
void f(T head, Args... arg){
    
}

int main(int argc, char** argv){
    if(argc != 1){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    return 0;
}