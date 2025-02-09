#include <iostream>
#include "library.h"
#include <vector>
using namespace std;

int main(){
    FullTimeEmployee fulltimeemp("Alice",101,5000);
    PartTimeEmployee parttimeemp("Bob",102,15,20);
    Manager manaemp("Charlie",103,6000,10,20);
    vector<Employee*> employees;
    employees.push_back(&fulltimeemp);
    employees.push_back(&parttimeemp);
    employees.push_back(&manaemp);
    for (const auto&emp : employees){
        emp->display();
        cout<<endl;
    }
    return 0;
}