#include <iostream>
#include <cstdlib>

using namespace std;

class Base{
    protected:
        int a;
    public:
        Base(int a_) : a(a_){}
        void print() const{
            cout<<"Base "<< a <<endl;
        }
};
class Derived : public Base{
    protected:
        int b;
    public:
        Derived(int a_, int b_):Base(a_){
            b =b_;
        }
        void print() const{
            cout <<"Derived "<< a <<" "<<<endl;
            cout <<"Derived" <<b<<"" <<endl;
        }
};
int main(){
    Derived obj(1,2);
    obj.Base::print();
    obj.Derived::print();
}