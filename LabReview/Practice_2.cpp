#include <iostream>

using namespace std;

class Employee{
    protected:
        string name;
    public:
        int salary;
        //constructor
        Employee(string n): name(n) {};
        virtual double Salary() = 0;
        virtual ~Employee(){};
};

class FullTimeEmployee : public Employee{
    private:
        double MonthlySalary;
    public:
        //constructor
        FullTimeEmployee(string name, double salary) : Employee(name), MonthlySalary(salary){};
        double Salary() override{
            return MonthlySalary;
        }

};

class PartTimeEmployee : public Employee{
    private:
        double hourlyWage;
        int hour;
    public:
        //constructor
        PartTimeEmployee(string name, double hourlyWage_, int hour_) : Employee(name), hourlyWage(hourlyWage_), hour(hour_){
        };
        double Salary() override{
            return hourlyWage*hour;
        }

};
int main(){
    Employee* employees[2];
    employees[0] = new FullTimeEmployee("Alice", 5000);
    employees[1] = new PartTimeEmployee("Bob", 20, 60);

    for (int i = 0; i < 2; i++) {
        cout << employees[i]->Salary() << endl;
        delete employees[i];  // Free memory
    }

    return 0;
}