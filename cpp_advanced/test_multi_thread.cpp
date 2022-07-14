//
// Created by yaohua on 2022/4/30.
//
// unique_lock example
#include <iostream> 
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock

using namespace std;

std::mutex mtx;           // mutex for critical section 全局锁变量


// 值传递参数
void print_block (int n, char c) {
  // critical section (exclusive access to std::cout signaled by lifetime of lck):
  // std::unique_lock<std::mutex> lck (mtx);
  mtx.lock();
  for (int i=0; i<n; ++i) { 
      std::cout << c; 
    }
  std::cout << '\n';
  mtx.unlock();
}


// 引用传递
// 调用的时候需要使用ref或者cref
void add_1(int &a){
  a++;
}


int main ()
{
  std::thread th1 (print_block,50,'*');
  std::thread th2 (print_block,50,'$');

  th1.join();
  th2.join();

  int a = 0;
  // std::thread th3(add_1, a);  // 编译错误
  std::thread th3(add_1, std::ref(a));
  th3.join();
  cout << "a: " << a << endl;

  return 0;
}
