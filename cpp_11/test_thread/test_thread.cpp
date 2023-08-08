// Created by yaohua on 2022/4/30.

// unique_lock example
#include <iostream> 
#include <vector>

#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock
#include <atomic>


using namespace std;

std::mutex mtx;           // mutex for critical section 全局锁变量


// test without lock
void print_block (int n, char c) {
  for (int i=0; i<n; ++i) 
  { 
    std::cout << c;
  }
  std::cout << '\n';
}

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


void test_without_lock()
{
  cout << "basic_test" << endl;
  // default constructor
  // std::thread th_0;

  // init constructor: thread obj(func, parameter list)
  int num = 1000;
  std::thread th1 (print_block, num, '*');
  std::thread th2 (print_block, num, '$');

  // copy constructor: forbidden
  // move constructor

  // get thread ID 
  // thread::id tid_1 = th1.get_id();
  // cout << "tid_1: " << tid_1 << endl;

  // call function in parallel
  th1.join();  
  th2.join();
};

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

// reference 
// you should use 'ref' or 'cref'
void add_1(int &a) {
  a++;
}

void test_reference()
{
  cout << "test_reference" << endl;
  int a = 0;
  cout << "before a: " << a << endl;
  // std::thread th3(add_1, a);  // will cause compile ERROR!
  std::thread th3(add_1, std::ref(a));  // pass parameter by reference explicitly
  th3.join();
  cout << "after a: " << a << endl;
}


// test std::atomic和std::mutex
// int n = 0;  // computional error
atomic_int n(0);

void plus_val()
{
  for (size_t i=0; i<100000; i++) 
  {
    n += 1;
  }
}

void test_lock() 
{
  vector<thread> th;
  th.resize(1000);

  // create thread
  for(auto &x:th)
  {
    x = thread(plus_val);
  }
  // join
  for (auto &x:th)
  {
    x.join();
  }
  
  cout << n << endl;
}


int main ()
{
  // test_without_lock();
  test_with_lock();
  // test_reference();
  // test_lock();
  return 0;
}
