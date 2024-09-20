#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 

using namespace std;

int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;


    /* 初始化堆 */
    // 初始化小顶堆
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // 初始化大顶堆
    priority_queue<int, vector<int>, less<int>> maxHeap;

    /* 元素入堆 */
    maxHeap.push(1);
    maxHeap.push(3);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(4);

    /* 获取堆顶元素 */
    int peek = maxHeap.top(); // 5

    /* 堆顶元素出堆 */
    // 出堆元素会形成一个从大到小的序列
    for (size_t i = 0; i < 5; i++)
    {
        cout << maxHeap.top() << endl;
        maxHeap.pop();
    }
    
    /* 获取堆大小 */
    int size = maxHeap.size();

    /* 判断堆是否为空 */
    bool isEmpty = maxHeap.empty();

    /* 输入列表并建堆 */
    // vector<int> input{1, 3, 2, 5, 4};
    // priority_queue<int, vector<int>, greater<int>> minHeap(input.begin(), input.end());


    // vector<int> a{3,2,5,4,6};
    // make_heap(a.begin(), a.end());

    // for (auto x:a)
    // {
    //     cout << x << endl;
    //     a.pop_back();
    // }
    
    // return 0;

}