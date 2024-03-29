#include <iostream>

using namespace std;

typedef union float_union
{
    float data;
    unsigned char buf[4];
} float_union;

int main(int argc, char** argv) {
    if(argc != 1){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    float_union a;
    a.data = 10;

    for (size_t i = 0; i < 4; i++)
    {
        cout << std::hex << a.buf[i] << " ";
    }
    cout << endl;

    return 0;
}