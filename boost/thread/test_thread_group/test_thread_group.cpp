#include <iostream>

#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/atomic.hpp>


using namespace std;

boost::atomic_int thread_counter(0);


void test_function()
{
    thread_counter++;
    cout << "thread launch " << thread_counter << endl;

    sleep(1);
}


int main(int argc, char** argv) {
    if(argc != 1){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    // basic thread 
    boost::thread t1(&test_function); 
    boost::thread t2(&test_function); 
    boost::thread t3(&test_function); 

    t1.join();
    t2.join();
    t3.join();

    boost::thread_group threads;
    for (size_t i = 0; i < 100; i++)
    {
        threads.create_thread(&test_function);
    }
    threads.join_all();

    return 0;
}