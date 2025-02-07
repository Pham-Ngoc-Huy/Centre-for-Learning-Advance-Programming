#include <iostream>
using namespace std;
class Vehicle{
    private:
    protected:
    public:
        //constructor
        Vehicle(){};
        virtual void start(){
            cout<<"Vehicle started"<<endl;
        } 
        virtual void drive(){
            cout<<"Driving a vehicle"<<endl;
        };   
        virtual ~Vehicle(){};
};
class Car:public Vehicle{
    public:
        virtual void drive() override{
            cout<<"Driving a car"<<endl;
        }
};
class Bike:public Vehicle{
    public:
        virtual void drive() override{
            cout<<"Riding a bike"<<endl;
        }
};

int main(){
    Vehicle* v1 = new Car();
    Vehicle* v2 = new Bike();
    v1 -> drive();
    v2 -> drive();
    delete v1;
    delete v2;
    return 0;
}