#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

int counter = 0;
std::mutex lock1, lock2;

std::mutex lock3, lock4;

// demo1: 
// a1 take lock1 and haven't release lock1
// then call a2
// a2() need to get lock1, however, lock1 is busy using by a1()
// in this condition, a2() will be block and always wait 

void a1();
void a2();

void a3();
void a4();


void a1()
{
    lock1.lock();
    std::cout << "output from a1" << std::endl;
    counter += 1;

    std::cout << "now call a2()" << std::endl;
    a2();
    lock1.unlock();
}


void a2()
{
    std::cout << "go in a2()" << std::endl;

    lock1.lock();
    std::cout << "output from a1" << std::endl;
    counter += 2;
    lock1.unlock();
}


// demo2: 
// a3() take lock3, a4() take lock4
// a3 wait for lock4(lock4 is using by a4()), a4 wait for lock3(lock3 is using by a3())
// in this condition, the two thread will block

void a3()
{
    lock3.lock();
    counter += 1;
    
    // for (size_t i = 0; i < 10000; i++)
    // {
    //     // delay for a while
    // }
    sleep(1);

    // acquire for lock4
    lock4.lock();
    std::cout << "a3 got lock4" << std::endl;
    lock4.unlock();

    lock3.unlock();
    
}

void a4()
{
    lock4.lock();
    counter += 1;
    // for (size_t i = 0; i < 10000; i++)
    // {
    //     /* code */
    // }
    sleep(1);
    // acquire for lock3
    lock3.lock();
    std::cout << "a4 got lock3" << std::endl;
    lock3.unlock();

    lock4.unlock();
}

int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    // demo1
    // std::thread t1(a1);
    // t1.join();

    // demo2
    std::thread t3(a3);
    std::thread t4(a4);

    t3.join();
    t4.join();

    std::cout << "counter: " << counter << std::endl;
    return 0;
}
