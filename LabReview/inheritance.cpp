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
//=================================================
// Calling Inherited Methods VII
// class Base{
//     public:
//         int b_var;
//     private:
//         void print(){
//             cout<<"Base"<<b_var<<endl;
//         }
// };
// class Derived : public Base{
//     public:
//         int d_var;
//         void print(){
//             cout<<"Derived"<<d_var<<endl;
//         }
// };
// int main(){
//     Derived obj;
//     obj.b_var = 10;
//     obj.d_var = 20;
//     obj.print();
//     return 0;
// }
// =================================================
//  Calling Inherited Methods VIII - has corrected - we can do the constructor in Derived by clone : Base constructor and adjust the inside variable for it 
// class Base{
//     public:
//         int b_var;
//         //constructor
//         Base(const int &b_var_) : b_var(b_var_)
//         {
//             cout<<"Base Constructor"<<b_var<<endl;
//         };
// };
// class Derived : public Base{
//     public:
//         int d_var;
//         //constructor
//         Derived(const int &d_var_) : Base(d_var_), d_var(d_var_)
//         {
//             cout<<"Derived Constructor"<<d_var<<endl;
//         }

// };
// int main()
// {
//     Derived obj(2);
//     return 0;
// }

//=================================================
// Polymorphism

// class Base {
//     public:
//         virtual void print() {
//             cout<<"Base"<<endl;
//         }
// };
// class Derived : public Base {
//     public:
//         void print() {
//             cout<<"Derived"<<endl;
//         }
// };
// int main() {
//     Base b_obj;
//     Derived d_obj;
//     b_obj.print(); //output base
//     d_obj.Base::print(); // output base
//     d_obj.print(); // output derived

//     Base *p;
//     // is it possible to assign the derived object to the base pointer?
//     p = &d_obj;
//     p ->print(); // sure it can be done - the output will be the base
//     return 0;
// }

//=================================================
//  virtual method I
// class Base {
//     public:
//         virtual void print() {
//             cout<<"Base"<<endl;
//         }
// };
// class Derived_1: public Base {
//     public:
//         virtual void print() {
//             cout<<"Derived_1"<<endl;
//         }
// };
// class Derived_2: public Base {
//     public:
//         virtual void print() {
//             cout<<"Derived_2"<<endl;
//         }
// };
// int main(){
//     Derived_1 d1_obj;
//     Derived_2 d2_obj;

//     Base *p;
//     p = &d1_obj;
//     p->print(); // output Derived_1
//     p = &d2_obj;
//     p->print(); // ouptut Derived_2
// }

//=================================================
// virtual method I

// class Base {
//     public:
//         virtual void print(){
//             cout<<"Base"<<endl;
//         }
// };

// class Derived_1 : public Base {
//     public:
//         void print() {
//             cout<<"Derived_1"<<endl;
//         } //overriding
//         void print(const int& val){
//             cout<<"Derived_1"<<val<<endl;
//         } //overloading
// };

// class Derived_2 : public Derived_1 {
//     public:
//         void print() {
//             cout<<"Derived_2"<<endl;
//         } //overriding
//         void print(const int& val){
//             cout<<"Derived_2"<<val<<endl;
//         } //overloading
// };

// int main(){
//     Derived_1 d1_obj;
//     Derived_2 d2_obj;

//     cout << "for p1"<<endl;
//     Base *p1;
//     p1 = &d1_obj;
//     p1->print(); // output Derived_1
//     p1 = &d2_obj;
//     p1->print(); // output Derived_2
//     p1->print(1); // Incorrect due to the type of p1 is Base -> don't have print(int val) method

//     Derived_1 *p2; // close to the derived class
//     p2 = &d1_obj;
//     p2 -> print();
//     p2 = &d2_obj; // 
//     p2 -> print();
//     p2 -> print(2); //output of derived 1
//     return 0;
// }

//=================================================
// To sum up -- all is supporting to the final point is abstract class
// Inheritance -> Polymorphism -> Virtual Method (Overidding/Overloading) / Using one base to point to Derived 
//-> Abstract Class

// Abstract Classes

// double sumArea(const int& size, Polugons* poly[])

// class Polygons{
//     public:
//         double area;
//         //constructor
//         Polygons() : area(0) {};
//         //pure virtual member function
//         virtual double computeArea() = 0;
//         static double sumArea(const int& size, Polygons* poly[])
//         {
//             double area = 0;
//             for (int i = 0; i < size; i++)
//                 area += poly[i]->computeArea();
//             return area;
//         }
// };

// class Triangles: public Polygons
// {
//     protected:
//         double base;
//         double height;
//     public:
//         Triangles(const double& base_, const double& height_) : base(base_), height(height_){
//         }
//     virtual double computeArea()
//     {
//         area = 0.5*base*height;
//         return area;
//     }
// };

// class Squares: public Polygons
// {
//     protected:
//         double side;
//     public:
//         Squares(const double& side_) : side(side_){
//         }
//     virtual double computeArea()
//     {
//         area = side*side;
//         return area;
//     }
// };

// class Rectangles: public Polygons
// {
//     protected:
//         double base;
//         double height;
//     public:
//         Rectangles(const double& base_, const double& height_) : base(base_), height(height_){
//         }
//     virtual double computeArea()
//     {
//         area = base*height;
//         return area;
//     }
// };

// int main()
// {
//     Triangles T(2.0,3.0);
//     Squares S(2.0);
//     Rectangles R(2.0,3.0);

//     Polygons* p_obj[3];

//     p_obj[0] = &T;
//     p_obj[1] = &S;
//     p_obj[2] = &R;

//     for (int i = 0; i < 3; i++)
//         cout<<p_obj[i]->computeArea()<<endl;
//     cout <<"Total_Area: "<<Polygons::sumArea(3,p_obj)<<endl;
//     return 0;
// }

//=================================================
// virtual Destructor I
class Base{
    public:
        virtual ~Base(){
            cout<<"Base Destructor"<<endl;
        }
};

class Derived : public Base{
    public:
        int size;
        double *v;
        //constructor
        Derived(const int& size_){
            size = size_;
            // v = new double[size];

        }
        virtual ~Derived(){
            cout<<"Derived Destructor"<<endl;
            //delete[] v;
        }
};
int main()
{
    Base *p_obj = new Derived(10); // this call in Base
    delete p_obj; // Base Destructor
    return 0;
}