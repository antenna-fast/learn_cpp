#include <iostream>
#include <string.h>
#include <sstream>
#include<iomanip>

using namespace std;


int main(int argc, char** argv){
    
    string a = "123.ply.txt";
    // char *p = strtok(a.c_str(), ".");

    // split string
    size_t pos = a.find(".");
    cout << "pos: " << pos << endl;

    cout << a.substr(0, pos) << endl;
    cout << a.substr(pos+1, 3) << endl;

    // replace 
    a = a.replace(a.begin(), a.begin() + pos, "hehe");
    cout << "a: " << a << endl;

    for (size_t i = 0; i < 5; i++)
    {
        stringstream ss;
        ss << setfill('0') << setw(6) << i;
        // ss << setw(6) << i;  
        cout << ss.str() << endl;
    }    

    return 0;
}
