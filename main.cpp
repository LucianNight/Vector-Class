#include <iostream>
#include <sstream>
#include "vector.h"


using namespace std;


int main()
{
    
    CIST2362::vector<int> ints;
    for (unsigned int i = 0; i < 200; ++i){
        ints.push_back(i);
        cout << ints.at(i) << endl;
        cout << "size: " << ints.size() << endl;
        cout << "capacity: " << ints.capacity() << endl;
        }
    
    
    //cout << ints.at(5) << endl;
    /*

    cout << "front: " << ints.front() << endl;
    cout << "back: " << ints.back() << endl;
    cout << "size: " << ints.size() << endl;
    cout << "popback: " << ints.pop_back() << endl;
    cout << "size: " << ints.size() << endl;
    cout << "newback: " << ints.back() << endl;
    cout << "[elmnt 7]: " << ints[7] << endl;
    cout << "size: " << ints.size() << endl;
    cout << "[elmnt 8]: " << ints[8] << endl;
    ints.insert(8,25);
    cout << "[elmnt 8]: " << ints[8] << endl;
    cout << "[elmnt 9]: " << ints[9] << endl;
    cout << "elmnt.at(9) " << ints.at(9) << endl;
    cout << "size: " << ints.size() << endl;


    */

    
    

    return 0;
}
