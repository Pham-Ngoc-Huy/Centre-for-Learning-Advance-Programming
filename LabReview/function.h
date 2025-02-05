#ifndef _STUDENT_CLASS_
#define _STUDENT_CLASS_
#include <iostream>
#include <cmath>
using namespace std;

class Student{
    private:
        int student_no; //row of matrix 
        int score_no; //col of matrix
        double** scores;
        double input_score;  
    protected:
    public:
        //constructor
        Student (const int& r, const int& c);
        // automate deconstruction
        ~Student();
        // allocate the slot
        void allocate();
        // deallocate the slot
        void deallocate();
        // initialization
        void zeros();
        // create input to the matrix
        void input();
        // get entry
        double getScore(const int& r, const int& c) const;
        // print
        void print();
        // Calculate the total score of the student
        Student calculateTotalScore();
        // Count student has larger score than the first one
        int countStudent();
};

#endif


