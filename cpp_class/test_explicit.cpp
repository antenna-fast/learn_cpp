#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;


class Str
{
public:
	// 用C风格的字符串p作为初始化值
	explicit Str(const char*p) {
		cout << p << endl;
	}
	//本意是预先分配n个字节给字符串
	explicit Str(int n) {
		cout << n << endl;
	}
};


int main(int argc, char** argv) {
    if(argc != 1) {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    // implicit type transformation
    int a = 1;
    long int b = a + 1;

    std::cout << "b: " << b << ",  typeid(b).name(): " << typeid(b).name() << std::endl;

    // Str str1 = "hh";  // implicit trans
    Str str2(10);  
    
    return 0;
}