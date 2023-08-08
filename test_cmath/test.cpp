#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    if(argc != 1){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;

    int res = std::floor(3.3); 
    cout << res << endl;

    res = std::ceil(3.33);
    cout << res << endl;

    return 0;
}
