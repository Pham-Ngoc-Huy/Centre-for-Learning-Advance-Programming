#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    vector<string>numbers;
    string read;
    string num;
    getline(cin,read);
    stringstream ss(read);
    while (getline(ss,num, ',')){
        numbers.push_back(num);
    }
    for (const string& i:numbers){
        cout<<i<<endl;
    }
    return 0;
}