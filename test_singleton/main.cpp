// test singleton mode

#include <iostream>

using namespace std;


class Tracker
{
public:

    static Tracker* getInstance()
    {
        if(instance == NULL)
        {
            instance = new Tracker();
        }
        return instance;
    }

private:
    // set default constructor and distructor as private
    Tracker();
    ~Tracker();

    // set copy-constructor and assign-constructor as private
    Tracker(const Tracker& signal);
    const Tracker &operator=(const Tracker &signal);  // TODO: ?

    static Tracker* instance;
};

Tracker::Tracker()
{
    std::cout << "Tracker() called." << std::endl;
}

Tracker::~Tracker()
{
    std::cout << "~Tracker() called." << std::endl;
}

Tracker* Tracker::instance = NULL;


int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        cout << " argc not match, Usage: " << endl;
        return -1;
    }
    
    // test singleton mode
    // yes, you will see that, *tracker_instance_1 = *tracker_instance_2
    Tracker *tracker_instance_1 = Tracker::getInstance();
    std::cout << "tracker1: " << tracker_instance_1 << std::endl;

    Tracker *tracker_instance_2 = Tracker::getInstance();
    std::cout << "tracker2: " << tracker_instance_2 << std::endl;

    return 0;
}
