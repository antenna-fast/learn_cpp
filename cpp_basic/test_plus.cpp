// Author: Yaohua Liu
// date: 2024-01-15

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    int cnt = 2;
    for (size_t i = 0; i < 3; i++)
    {
        // cout << std::to_string(cnt++) << endl;  // 2 3 4
        cout << std::to_string(++cnt) << endl;  // 3 4 5
    }
    
    return 0;
}