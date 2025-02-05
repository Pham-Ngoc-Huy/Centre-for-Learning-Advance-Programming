#include <iostream>
using namespace std;

// class Base
// {
//     private:
//         int b_private; //(always)
//         // inaccessible to Derived class
//     public: // is accessible
//         int b_public;
//         Base() : b_private(1), b_protected(2), b_public(3) {} // constructor
//     protected: // is accessible
//         int b_protected;

// };
// class Derived : public Base
// {
//     private:
//         int d_private;
//         // inaccessible to Base class
//     protected: // is accessible
//         int d_protected;
//     public: // is accessible
//         int d_public;
//         Derived() : d_protected(4), d_public(5) {} // constructor

// };
// class DerivedofDerived : public Derived
// {
//     public:
//         void print()
//         {
//             cout << b_protected <<endl;
//             cout << b_public <<endl;
//             cout << d_protected <<endl;
//             cout << d_public <<endl;
//         }
//     protected:

// };
// int main()
// {
//     DerivedofDerived obj;
//     obj.d_public = 20;
//     obj.b_public = 30;
//     obj.print();
//     return 0;
// }

//================================================================================================

// class Base
// {
//     public:
//         int var;
//         void print() {
//             cout <<"Base"<< var << endl;
//         }
//         //constructor
//         Base() {
//             cout<<"Base Constructor"<<endl;
//         }
// };
// class Derived : public Base
// {
//     public:
//         int var;
//         void print() {
//             cout<<"Derived"<< var << endl;
//         }
//         //constructor
//         Derived() {
//             cout<<"Derived Constructor"<<endl;
//         }
// };
// int main()
// {
//     Derived obj;
//     // obj.var = 10;
//     // obj.Base::var = 20;
//     // obj.Base::print();
//     // obj.print();
//     return 0;
// }

//=================================================
// class Base
// {
//     protected:
//         int b_var;
//     public:
//         //constructor
//         Base() {
//             cout<<"Base Constructor"<<endl;
//             b_var= 1;
//         }
// };
// class Derived : protected Base
// {
//     public:
//         int d_var;
//         //constructor
//         Derived(const int &d_var_) {
//             cout<<"Derived Constructor"<<endl;
//             d_var = d_var_;
//         }
//         void print() {
//             cout<<"Base Variable: "<<b_var<<endl;
//             cout<<"Derived Variable: "<<d_var<<endl;
//         }
// };

// int main()
// {
//     Derived obj(2);
//     obj.print();
//     return 0;
// }

//=================================================

// class Base{
//     protected:
//         int b_var;
//     public:
//     //constructor
//         Base(const int &b_var_) {
//             // cout<<"Base Constructor"<<endl;
//             b_var = b_var_;
//         }
// };
// class Derived : public Base{
//     public:
//         int d_var;
//         //constructor
//         Derived(const int &b_var_, const int &d_var_) : Base(b_var_) {
//             // cout<<"Derived Constructor"<<endl;
//             d_var = d_var_;
//         }
//         void print() {
//             cout<<"Base Variable: "<<b_var<<endl;
//             cout<<"Derived Variable: "<<d_var<<endl;
//         }
// };

// int main(){
//     Derived obj(1,2);
//     obj.print();
//     return 0;
// }

//=================================================
//Destructor --> with the destructor of the derived class is called first and then the destructor of the base class is called.

// class Base{
//     public:
//         ~Base(){
//             cout<<"Base Destructor"<<endl;
//     }
// };
// class Derived : public Base{
//     public:
//         ~Derived(){
//         cout<<"Derived Destructor"<<endl;
//     }
// };
// int main(){
//     Derived obj;
//     return 0;
// }

//=================================================
//Calling inherited methods I

// class Base{
//     public:
//         int b_var;
//         void print(){
//             cout<<"Base"<<b_var<<endl;
//         }
// };
// class Derived : public Base{
//     public:
//         int d_var;
//         // void print(){
//         //     cout<<"Derived"<<d_var<<endl;
//         // }
// };
// int main(){
//     Derived obj;
//     // obj.b_var = 10;
//     // obj.d_var = 20;
//     // obj.Base::print();
//     // obj.print();

//     obj.b_var = 1;
//     obj.d_var = 2;
//     obj.print();
//     return 0;
// }

class Base{
    public:
        int b_var;
    private:
        void print(){
            cout<<"Base"<<b_var<<endl;
        }
};
class Derived : public Base{
    public:
        int d_var;
        void print(){
            cout<<"Derived"<<d_var<<endl;
        }
};
int main(){
    Derived obj;
    obj.b_var = 10;
    obj.d_var = obj.b_var;
    obj.print();
    return 0;
}
// Stop at Calling Inherited Methods VI