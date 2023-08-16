#include <iostream>

#include <cmath>

using namespace std;

int main(int argc, char** argv) {
    if(argc != 1) {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;

    double a = 1;

    // for (size_t i = 0; i < 360; i++)
    {
        double rad = atan2(1, 1e-10) * 57.3;
        std::cout << rad << std::endl;
    }
        
    return 0;
}