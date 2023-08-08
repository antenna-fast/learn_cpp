//
// Created by yaohua on 2022/5/14.
//

#include <iostream>
#include <queue>


using namespace std;

int main()
{
    std::deque<vector<int> > q1;

    for (int i = 0; i < 10; i++)
    {
        vector<int> a{i, i*2, i*3};
        q1.push_front(a);
        cout << "push_front: " << a.at(0) << ", " << a.at(1) << ", " << a.at(2) << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        auto tmp = q1.front();
        cout << tmp.at(0) << ", " << tmp.at(1) << ", " << tmp.at(2) << endl;
        q1.pop_front();
    }
    
    cout << "size: " << q1.size() << endl;

    return 0;
}