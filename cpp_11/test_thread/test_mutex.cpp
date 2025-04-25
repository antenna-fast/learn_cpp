#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int sum = 0;
std::mutex mtx;

void t_sum()
{
    // no lock error but, if we lock, the efficient will loss a lot.
    mtx.lock();
    for (size_t i = 0; i < 1000000; i++)
    {
        sum++;
    }
    mtx.unlock();  // if you forget to unlock, the program will block at here
}


int main(int argc, char** argv) {
    if(argc != 1){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    std::thread th1 (t_sum);
    std::thread th2 (t_sum);

    th1.join();
    th2.join();

    std::cout << "sum: " << sum << std::endl;

    return 0;
}