#ifndef _DEFINE_EMPLOYEE_
#define _DEFINE_EMPLOYEE_
#include <iostream>
using namespace std;

class Employee{
    protected:
        string name;
        int id;
    public:
        //constructor
        // Employee(): name(" "), id(0) {};
        Employee(const string& name_, const int& id_): name(name_), id(id_) {};
        virtual double calculateSalary() const = 0;
        virtual void display() const = 0;
        //destructor
        virtual ~Employee(){};
};
class FullTimeEmployee : virtual public Employee{
    protected:
        int monthlysalary;
    public:
        FullTimeEmployee(const string& name_, const int& id_, const int& salary_): Employee(name_, id_), monthlysalary(salary_){};
        double calculateSalary() const override;
        void display() const override;
};
class PartTimeEmployee : virtual public Employee{
    protected:
        int hourlywage;
        double hoursworked;
    public:
        PartTimeEmployee(const string& name_, const int& id_, const int& wage_, const double& hours_): Employee(name_, id_), hourlywage(wage_), hoursworked(hours_){};
        double calculateSalary() const override;
        void display() const override;
};
class Manager : public FullTimeEmployee, public PartTimeEmployee{
    protected:
    public:
        Manager(const string& name_, int id_, double salary_, double wage_, double hours_):
        Employee(name_, id_), FullTimeEmployee(name_,id_,salary_), PartTimeEmployee(name_,id_,wage_,hours_) {};
        double calculateSalary() const override;
        void display() const override;
};
#endif