#include <iostream>
using namespace std;

//global variable
int xGlobal=1;
int x = 10;
int main(){
    //local var
    for (int i= 0; i <10; i++){
        cout << "i="<<i<<endl;
    } // i is a local var inside the for loop
    cout <<"i="<<xGlobal<<endl;
    // i is out-of-scope -> deleted


    // New explore -> same name but different bracket which mean different interaction and scope - not violate each other 
    cout << "L14:"<<&x <<endl;
    int x = 1;
    cout << "L16:"<<&x <<endl;

    {
        int x = 10;
        cout << "L20:"<<&x <<endl;

    }
}
