// notify_one
// notify_all


// code ref: https://en.cppreference.com/w/cpp/thread/condition_variable
// ref: 
// https://cloud.tencent.com/developer/article/1584067
// 生产者消费者模式: https://zhuanlan.zhihu.com/p/73442055

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready;
bool processed = false;

void worker_thread()
{
    // wait untail main() send data

    // Acquire a std::unique_lock<std::mutex> on the mutex used to protect the shared variable
    std::unique_lock<std::mutex> lk(m); 

    cv.wait(lk, [] {return ready;});

    // after the wait, worker own the lock
    std::cout << "Worker start processing" << endl;
    data += " after worker process";

    // Send data back to main()
    processed = true;
    cout << "Worker process done" << endl;

    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)    
    lk.unlock();

    // wakeup one thread who are waitting for me
    cv.notify_one(); 
}


int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        cout << " argc not match, Usage: " << endl;
        return -1;
    }
    std::cout << "running: " << argv[0] << std::endl;
    
    std::thread worker(worker_thread);
    
    // define the data
    data = "Example data from main";

    // main() send data ready to worker thread
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        cout << "main() data ready" << endl;
    }
    cv.notify_one();

    // wait for the worker
    {
        std::unique_lock<mutex> lk(m);
        cv.wait(lk, [] {return processed; });  // wait the worker
    }
    cout << "back in main(), data is: " << data << endl;
    worker.join();

    return 0;
}