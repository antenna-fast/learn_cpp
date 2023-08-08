#include <iostream>
#include <cassert>
#include <thread>

#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <boost/atomic.hpp>

using namespace std;

boost::atomic_int thread_counter(0);

// demo1: void function
void hello()
{
  thread_counter ++;  // ERROR: hello world from boost thread hello world from boost thread 22
  cout << "hello world from boost thread " << thread_counter << endl;
}

// demo2: 

// bind

int main(int argc, char** argv) {
    if(argc != 1){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    boost::thread hello_thread_1(&hello);
    boost::thread hello_thread_2(&hello);

    hello_thread_1.join();
    hello_thread_2.join();

    assert(thread_counter == 2);

    return 0;
}