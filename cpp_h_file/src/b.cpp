// Author: Yaohua Liu
// date: 2025-04-23

#include <iostream>
#include "a.h"
#include "b.h"

using namespace std;


int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    

    return 0;
}

