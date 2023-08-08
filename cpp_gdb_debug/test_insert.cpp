// inserting into a vector
#include <iostream>
#include <vector>

using namespace std;


template <typename T>
void print_vector(const std::vector<T> &input_vector) {
    for (size_t i = 0, length = input_vector.size(); i < length; i++) {
        cout << "idx: " <<  i << ": " << input_vector[i] << endl;
    }
    return;
}


int main ()
{
    std::vector<int> myvector (3, 100);
    std::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert (it , 200);

    myvector.insert (it, 3, 300);
    // print_vector(myvector);
    
    // If reallocations happen, the storage is allocated using the container's allocator, 
    // which may throw exceptions on failure (for the default allocator, 
    // bad_alloc is thrown if the allocation request does not succeed).

    // "it" no longer valid: Segmentation fault (core dumped)
    // myvector.insert (it, 10, 800);
    // print_vector(myvector);

    // get a new one:
    it = myvector.begin();

    std::vector<int> anothervector (2,400);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray+3);

//   std::cout << "myvector contains:";
//   for (it=myvector.begin(); it<myvector.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

  return 0;
}