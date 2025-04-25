// Author: Yaohua Liu
// date: 2025-04-11

#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    int a = 2;
    switch (a)
    {
        case 1: case 2:
            std::cout << "1 or 2" << std::endl;
            break;  // if no break, it will judge the following line    
        default:
            std::cout << "default" << std::endl;
            break;
    }

    return 0;
}