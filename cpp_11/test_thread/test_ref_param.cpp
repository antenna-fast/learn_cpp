// Author: Yaohua Liu
// date: 2025-04-25

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


// reference 
// you should use 'ref' or 'cref'
void add_1(int &a) {
    a++;
}



int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    std::cout << "test_reference" << std::endl;

    int a = 0;
    cout << "before a: " << a << endl;

    // std::thread th3(add_1, a);  // will cause compile ERROR!
    std::thread th3(add_1, std::ref(a));  // pass parameter by reference explicitly
    th3.join();
    cout << "after a: " << a << endl;

    return 0;
}