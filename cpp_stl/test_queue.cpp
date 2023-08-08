//
// Created by yaohua on 2022/5/14.
//
// Note: 
// queue can not be iterate! the value can be get from front()
// queue can inly insert value to end, and can only pop a value from front

#include <iostream>
#include <queue>


using namespace std;

int main()
{
    std::queue<int> q1;

    for (size_t i = 0; i < 10; i++)
    {
        q1.push(i);
        cout << "push: " << i << endl;
    }

    for (size_t i = 0; i < 4; i++)
    {
        cout << q1.front() << endl;;
        q1.pop();  // pop front
    }
    
    cout << "size: " << q1.size() << endl;

    return 0;
}