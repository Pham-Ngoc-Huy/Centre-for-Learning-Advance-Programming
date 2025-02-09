#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    vector<string>numbers;
    string read;
    string num;
    //char type: using in for get an element in string
    getline(cin,read);
    stringstream ss(read);
    while (getline(ss,num, ',')){ // get each element in an string "23,55,45" - seperate by ','
    //The getline function is used with ss to extract substrings separated by ,.
    //Each extracted substring is stored in num and added to numbers using push_back.
        numbers.push_back(num); //adding back to the vector
    }
    for (const string& i:numbers){ // loop for each element in vector
        cout<<i<<endl;
    }
    return 0;
}
