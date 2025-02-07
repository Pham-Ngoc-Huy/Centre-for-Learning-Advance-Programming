#include <iostream>

using namespace std;

class Animal{
    public:
        //constructor:
        Animal(){};
        virtual void speak(){
            cout<<"Some animal sound"<<endl;
        }
        virtual ~Animal(){};
};

class Dog : public Animal{
    public:
        //constructor:
        void speak() override{
            cout<<"Woof"<<endl;
        }
};
class Cat : public Animal{
    public:
        //constructor:
        void speak() override{
            cout<<"Meow"<<endl;
        }
};

int main(){
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();
    a1->speak();  // Calls Dog::speak()
    a2->speak();  // Calls Cat::speak()

    delete a1;
    delete a2;

    return 0;
}