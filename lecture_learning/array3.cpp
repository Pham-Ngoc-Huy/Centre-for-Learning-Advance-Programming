#include <iostream>
using namespace std;

int main(){
    int nEle;
    cout<<"Input number of element: ";
    cin >> nEle;
    int* v;
    v = new int[nEle];
    for (int i = 0; i < nEle; ++i){
        cout <<"Input v[" << i << "]:"<<endl;
        cin >> v[i];
    }
    for (int i = 0; i < nEle; ++i){
        cout << " " << v[i] <<endl;   
    }
    cout<<endl;
    delete[] v;
}

