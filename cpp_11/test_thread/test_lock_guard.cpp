// Author: Yaohua Liu
// date: 2025-04-25

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

size_t sum = 0;
std::mutex mtx;

void t_sum()
{
    std::lock_guard lock(mtx);  // it will unlock automically
    for (size_t i = 0; i < 100000; i++)
    {
        sum ++;
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
    std::thread th2(t_sum);

    th1.join();
    th2.join();

    std::cout << "sum: " << sum << std::endl;

    return 0;
}