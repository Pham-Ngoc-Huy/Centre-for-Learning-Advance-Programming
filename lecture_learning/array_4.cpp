#include <iostream>
using namespace std;

int main(){
    int rows = 5;
    int cols = 4; 
    int** A;
    A = new int* [rows]; // master link
    for (int i = 0 ; i < rows; i++){
        A[i] = new int[cols]; 
        // delete inside out
    }
    for (int i = 0 ; i < rows; i++){
        delete[] A[i];
    }
    delete[] A;
    

}