#include <iostream>
#include <stdio.h>
#include <boost/shared_ptr.hpp>

using namespace std;

class A {
public:
    void print() 
    {
        printf("class A print!\n");
    }

    ~A()
    {
        cout << "Destroy A" << endl;
    }
};

int main(int argc, char **argv) {
    boost::shared_ptr<A> a1(new A());
    a1->print();
    cout << a1.use_count() << endl;

    boost::shared_ptr<A> a2(a1);
    cout << a2.use_count() << endl;

}
