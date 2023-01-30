// functor
// makeup a class like function

// ref: https://www.programiz.com/cpp-programming/functors

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;


// demo 1: void input and void output functor
class Functor
{
    public:
    void operator()(){
        cout << "Hello World from operator()" << endl;
    }
};


// demo2: with parameter and return value
class Add
{
    public:
    // return_type  operator  overload_operator()   (params_list, ...) { // body}
    int operator() (int a, int b){  
        return a + b;
    }
};


// demo3: with member variable
class AddWithVariable
{
    public:
        AddWithVariable(int init_val){
            tmp = init_val;
        }

        int operator()(int val){
            return tmp + val;
        }

    private:
        int tmp;
};


// demo4: #include <functional>
// Predefined Functor with STL
void testFunctional()
{
    vector<int> v = {10, 30, 20, 50, 3, 4};

    // sort the vector
    sort(v.begin(), v.end(), greater<int>());

    for(auto x:v){
        cout << x << " ";
    }
    cout << endl;
}


// demo5: template functor
template <typename T>
class AddT
{
    public:
        AddT(const T init_val):tmp(init_val){}

        T operator() (const T val){
            return tmp + val;
        }

    private:
        T tmp;
};


int main(int argc, char** argv){
    if(argc != 1){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    cout << "demo 1: the most naive functor" << endl;
    Functor f;
    f(); 

    cout << endl;

    cout << "demo 2: functor with parameters and return value" << endl;
    Add add;
    int res = add(1, 2);
    cout << "res: " << res << endl;
    cout << endl;

    cout << "demo 3: " << endl;
    AddWithVariable addWithVal(3);
    cout << "addWithVal(4): " << addWithVal(4) << endl;
    cout << endl;

    cout << "demo 4: functional" << endl;
    testFunctional();
    cout << endl;

    cout << "demo 5: functor using template" << endl;
    int a = 10;
    AddT<int> addT(a);
    cout << addT(20) << endl;

    return 0;
}