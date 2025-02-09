#include <iostream>
using namespace std;

int main(){
    // 0D
    int a  = 10;
    // 1D array
    int v[4] = {1,2,3,4};
    // 2D array
    int A[4][3];
    A[0][0] = 1;A[0][1] = 2;A[0][2] = 3;
    A[1][0] = 4;A[1][1] = 5;A[1][2] = 6;
    A[2][0] = 7;A[2][1] = 8;A[2][2] = 9;
    A[3][0] = 10;A[3][1] = 11;A[3][2] = 12;

    cout<<"a=" << a<<endl;
    for (int i=0; i<4; i++){
        cout << " " << v[i] << "," <<endl;
    }
    cout << endl;

    for (int i = 0; i<4; i++){
        for (int j = 0; j<3 ;j++){
            cout << " " << A[i] << "," <<endl;
            cout << " " << A[j] << "," <<endl;
        }
    }

}
