// Author: Yaohua Liu
// date: 2024-03-04

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
    
    char *TZ;
    if((TZ = getenv("TZ"))){
        printf("TZ=%s\n",TZ);
        // return;
    }
    
    printf("TZ=%s \n", getenv("TZ"));

    return 0;
}