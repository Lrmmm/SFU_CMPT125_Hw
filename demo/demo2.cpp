#include<iostream>
using namespace std;
class Person
{
public:
    Person(){
        cout  << "Person Constructed!" << endl;
        cout << "I am " << count << "th person" <<endl;
        count++;
    }
private:
    static int count;
};

int Person::count = 0;


int main()
{
    Person* p1 = new Person[3];
    return 0;
}