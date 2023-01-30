#include <iostream>
#include <string>
#include <tuple>


using namespace std;

int main(int argc, char** argv){
    cout << argv[0] << endl;

    std::tuple<int, double, string> t = {1, 1.2, "1123"};
    for (size_t i = 0; i < 3; i++)
    {
        cout << std::get<2>(t)  << endl;;
    }
    
    return 0;
}

