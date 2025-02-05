#include <iostream>
#include "function.h"

using namespace std;

int main() {
    int students, scores = 5;
    cout<<"Enter number of Students: "<<endl;
    cin>>students;
    Student A(students, scores);
    A.allocate();
    A.zeros();
    A.input();
    Student B = A.calculateTotalScore();
    B.print();
    int C = B.countStudent();
    cout <<"Number of student that have higher score than Kristen's grade: "<< C<<endl;
    return 0;
}
