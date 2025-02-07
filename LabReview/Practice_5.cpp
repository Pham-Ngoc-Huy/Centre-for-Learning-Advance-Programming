#include <iostream>
using namespace std;

class Base{
    public:
        //constructor
        Base(){
            cout<<"Base Constructor"<<endl;
        }
        virtual ~Base(){
            cout<<"Base Destructor"<<endl;
        }
};
class Derived : public Base{
    public:
        //constructor
        Derived(){
            cout<<"Derived Constructor"<<endl;
        }
        ~Derived(){
            cout<<"Derived Destructor"<<endl;
        }
};

int main(){
    Base* obj = new Derived();
    delete obj;
    return 0;
}