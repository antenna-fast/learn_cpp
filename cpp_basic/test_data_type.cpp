// Author: Yaohua Liu
// date: 2024-01-08

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    // float a = 4417666.123;  // you will see: a: 4417666
    double a = 4417666.123;

    std::cout << std::setprecision(15) << "a: " << a << endl;


    double x = 441158.123;
    double y = 4425356.123;
    double z = 30.123;


    return 0;
}