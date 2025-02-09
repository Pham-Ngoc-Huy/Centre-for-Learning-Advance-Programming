#include <iostream>
#include "library.h"

using namespace std;

double FullTimeEmployee::calculateSalary() const {
    return monthlysalary;
}
void FullTimeEmployee::display() const{
    cout << "Full-Time Employee: "<<name <<" ("<<"ID: "
    <<id<<" )"<<"\nSalary: "<<"$"<<calculateSalary()<<endl;
}
double PartTimeEmployee::calculateSalary() const {
    return hourlywage * hoursworked;
}
void PartTimeEmployee::display() const{
    cout << "Hours Worked: "<<hoursworked<<", "<<"Hourly Wage: "<<"$"<<hourlywage
    <<"\nSalary: "<<"$"<<calculateSalary()<<endl;
}
double Manager::calculateSalary() const {
    return FullTimeEmployee::calculateSalary() + PartTimeEmployee::calculateSalary();
}   
void Manager::display() const{
    cout <<"Manager: "<<FullTimeEmployee::name<<" (ID: "<<FullTimeEmployee::id<<")"
    <<"\nBase Salary: "<<"$"<<FullTimeEmployee::calculateSalary()
    <<", Bonus: "<<"$"<<PartTimeEmployee::calculateSalary()
    <<"\nTotal Salary: "<<"$"<<calculateSalary()<<endl;
}


