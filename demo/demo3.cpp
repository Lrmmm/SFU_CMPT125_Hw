#include<iostream>
using namespace std;
class Person
{
public:
    Person(){
        cout << "Person created" <<endl;
    }
    Person(int age)
    {
        this->age = age;
        cout << "Person created" <<endl;
    }
private:
    int age;
};

int main()
{
    Person* nP = new Person[3];
    nP[2] = Person(5);
    return 0;
}