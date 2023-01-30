#include <iostream>
#include <vector>


using namespace std;


int main(int argc, char** argv){
    if (argc != 3){
        cout << "parameter list error... " << endl;
        cout << "Usage: ./app param1, param2" << endl;
        return -1;
    }

    cout << argv[0] << endl;
    cout << argv[1] << endl;
    cout << argv[2] << endl;
    
    cout << "Hello, World!" << endl;

}