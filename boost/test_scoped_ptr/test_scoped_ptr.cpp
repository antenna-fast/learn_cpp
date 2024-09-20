#include <iostream>
#include <stdio.h>
#include <boost/scoped_ptr.hpp>

using namespace std;

class A {
public:
    void print() 
    {
        cout << "class A print!" << endl;
    }
    
    ~A()
    {
        cout << "Class A destroy" << endl;
    }
};

int main(int argc, char **argv) {

    // naive class usage
    A a_1;
    a_1.print();
    
    A a_2(a_1);

    // BOOST:scoped_ptr

    boost::scoped_ptr<A> b_1(new A());
    b_1->print();

    // boost::scoped_ptr<A> b_2(b_1);  // compile error, b_1 can not be copy!

}
