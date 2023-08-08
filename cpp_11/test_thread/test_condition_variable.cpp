// notify_one
// notify_all


// code ref: https://en.cppreference.com/w/cpp/thread/condition_variable

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
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [] {return ready;});

    // after the wait, worker own the lock
    cout << "Worker start processing" << endl;
    data += " after worker process";

    processed = true;
    cout << "Worker process done" << endl;
    lk.unlock();
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

    // send data to worker
    {
        std::lock_guard<mutex> lk(m);
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