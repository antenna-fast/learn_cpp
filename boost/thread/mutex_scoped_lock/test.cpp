#include <iostream>
#include <thread>
#include <boost/thread/mutex.hpp>


using namespace std;

boost::mutex mtx;


// test with lock
void print_block_lock (int n, char c) { 
  mtx.lock();  // protective area
  for (int i=0; i<n; ++i) 
  { 
    std::cout << c;
  }
  std::cout << '\n';
  mtx.unlock();  // NOTE: if you forget to unlock, the other thread called this code fragment will be blocked!
}


// test with boost:mutex:scoped_lock
void print_block_scoped_lock (int n, char c) { 
    // mtx.lock();  // protective area
    boost::mutex::scoped_lock lock(mtx);
    for (int i=0; i<n; ++i) 
    { 
    std::cout << c;
    }
    std::cout << '\n';
    //   mtx.unlock();  // NOTE: if you forget to unlock, the other thread called this code fragment will be blocked!

    // now, you do NOT have to un lock here! 
    // because the scoped lock is smart lock which can release automatically
}

void test_with_lock()
{
  cout << "lock_test" << endl;

  // init constructor: thread obj(func, parameter list)
  int num = 1000;
  std::thread th1 (print_block_lock, num, '*');
  std::thread th2 (print_block_lock, num, '$');

  // call function in parallel
  th1.join();  
  th2.join();
}

int main(int argc, char** argv){
    if(argc != 1){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    test_with_lock();

    return 0;
}