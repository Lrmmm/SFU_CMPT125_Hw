#include "demo.h"
#include <iostream>
using namespace std;
int Person::count = 10;
Person::Person()
{
    age = 0;
    length = 1;
    count++;
}

void Person::setAge(int age)
{
    this->age = age;
}

void Person::setLength(int length)
{
    this->length = length;
}

void Person::printPerson()
{
    cout << "age=" << age << "  length="  << length << "  count=" << count <<endl;
}

Person::~Person()
{
    count--;
    cout << "Destoryed Person count=" << count <<endl;
}
