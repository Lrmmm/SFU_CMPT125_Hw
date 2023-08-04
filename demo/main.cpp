#include "demo.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    Person p1;
    p1.printPerson();
    std::cout << std::left;
    cout << setw(22) << "Width" << "12" << endl;
    cout << setw(22) << "Height" << "8" << endl;
    cout << setw(22) << "xLocation" << "23" << endl;
    cout << setw(22) << "yLocation" << "11" << endl;
    cout << setw(22) << "area" << "96" << endl;
    cout << setw(22) << "rectanglesCreated" << "5" << endl;
    cout << setw(22) << "rectanglesExisting" << "3" << endl;
    cout << std::setw(0);
    return 0;
    
}