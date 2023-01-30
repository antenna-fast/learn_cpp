#include <iostream>
#include <vector>

using namespace std;

namespace base
{
class Animal
{
    public:
        float getHeight();         
        float getWeight();

    private:
        float height;
        float weight;
};

float Animal::getHeight()
{
    return height;
}

float Animal::getWeight()
{
    return weight;
}

}// namespace human


namespace base
{
// class Animal;

class Zone
{
    public:

    private:
        vector<Animal> Animals;
};

} // namespace base


int main(int argc, char** argv){
    if(argc != 1){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    return 0;
}