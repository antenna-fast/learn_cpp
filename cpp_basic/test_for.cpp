#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <limits>
#include <vector>
#include <algorithm>


using namespace std;


void basic_test()
{
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            cout << " " << i << "," << j << "   ";
            if(j > 5){
                break;  // only break this aspect of loop
            } 
        }
        cout << endl;
    }

    cout << "fabs: " << fabs(std::numeric_limits<unsigned long int>::max()) << endl;
    cout << "max: " << std::numeric_limits<unsigned long int>::max() << endl;
    ulong a = numeric_limits<unsigned long int>::max();
    ulong b = 0;
    cout << ((a > b) ? (a - b) : (b - a)) << endl;
}


// test for_each 
struct Sum
{
    void operator()(int n) { sum += n; }
    int sum{0};  // C++11 init method
    // int sum = 0;
};

int test_for_each()
{
    std::vector<int> nums{3, 4, 2, 8, 15, 267};
    
    // lambda
    auto print = [](const int& n) { std::cout << " " << n; };
 
    std::cout << "before:";
    std::for_each(nums.cbegin(), nums.cend(), print);
    std::cout << '\n';
    
    // plus one for each element 
    std::for_each(nums.begin(), nums.end(), [](int &n){ n++; });
 
    // calls Sum::operator() for each number
    Sum s = std::for_each(nums.begin(), nums.end(), Sum());
 
    std::cout << "after: ";
    std::for_each(nums.cbegin(), nums.cend(), print);
    std::cout << '\n';
    std::cout << "sum: " << s.sum << '\n';
}


int main(int argc, char** argv){
    
    test_for_each();

    return 0;
}
