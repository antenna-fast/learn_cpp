#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;

//! Print a progress bar with given progress. Remember to print a new line after progress reaches 1.0
inline void printProgressBar(float progress)
{
    int bar_width = 70;
    std::cout << "\r[";
    int pos = static_cast<int>(bar_width * progress);
    for (int i = 0; i < bar_width; ++i)
    {
        if (i < pos)
            std::cout << "=";
        else if (i == pos)
            std::cout << ">";
        else
            std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %" << std::flush;
    if (progress == 1.0)
        std::cout << std::endl;
}


int main(int argc, char** argv){
    cout << argv[0] << endl;
    
    boost::filesystem::copy_file("1.txt", "2.txt", boost::filesystem::copy_option::overwrite_if_exists);

    // int loop=3;
    // while (loop-- >0)  // 2 1 0 
    // // while (--loop >0)     // 2 1
    // {
    //     cout << loop << endl;
    // }

    // for (size_t i = 0; i <= 100; i++)
    // {
    //     printProgressBar(i / 100.0);
    // }

    return 0;
}
