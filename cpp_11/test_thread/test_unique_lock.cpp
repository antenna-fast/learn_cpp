// Author: Yaohua Liu
// date: 2025-04-25

// state: TODO

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


size_t sum = 0;

void t_sum()
{
    for (size_t i = 0; i < 100000; i++)
    {
        sum++;
    }    
}

int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    

    std::thread th1(t_sum);
    th1.join();

    std::cout << "sum:" << sum << std::endl;

    return 0;
}