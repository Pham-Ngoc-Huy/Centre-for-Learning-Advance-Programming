#include <iostream>
#include "library.h"
using namespace std;

int main(){
    Circle c(5);
    Rectangle r(5,4);
    Sphere s(5);
    Cuboid cu(4,5,6);
    Shape *s_obj[4]; // this is polymorphism
    s_obj[0] = &c;
    s_obj[1] = &r;
    s_obj[2] = &s;
    s_obj[3] = &cu;
    for(int i = 0; i < 4; i++){
        s_obj[i]->display();

    }
    cout  <<endl;


}
