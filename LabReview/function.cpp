#include <iostream>
#include "function.h"

using namespace std;


//Constructor
Student:: Student(const int& r, const int& c){
    student_no = r;
    score_no = c;
    allocate();
}

void Student::allocate(){
    scores = new double*[student_no];
    for (int i = 0; i < student_no; i++)
        scores[i] = new double[score_no];
}

void Student::deallocate(){
    for (int i = 0; i < student_no; i++)
        delete[] scores[i];
    delete[] scores;
}


void Student::zeros(){
    for (int i = 0; i < student_no; i++){
        for (int j = 0; j < score_no;j++){
            scores[i][j] = 0;
        }
    }
}

Student::~Student(){
    deallocate();
}

void Student::input(){
    for (int i = 0; i < student_no; i++){
        for (int j = 0; j < score_no; j++){
            cout<<"Type your score in: ";
            cin>>input_score;
            scores[i][j] = input_score;
            cout<<endl;
            cout<<"You have type in row "<<i<<" column "<<j<<" with the value = "<<scores[i][j]<<endl;
        }
    }
}

Student Student::calculateTotalScore() {
    Student totalStudent(student_no, 1);  
    totalStudent.allocate(); 
    totalStudent.zeros();
    for (int i = 0; i < student_no; i++) {
        for (int j = 0; j < score_no;j++)
            totalStudent.scores[i][0] += scores[i][j];  // Sum up scores for each student
        }
    return totalStudent;  // Return the computed total scores

}

double Student::getScore(const int& r, const int& c) const { 
        if (r >= 0 && r < student_no && c >= 0 && c < score_no) {
            return scores[r][c];  // Return the score if indices are valid
        } else {
            cerr << "Error: Index out of bounds!" << endl;
            return -1;  // Return an invalid value to indicate an error
        }
    }

void Student::print(){
    cout << "Total scores for each student:\n";
    for (int i = 0; i < student_no; i++) {
        cout << "Student " << i + 1 << ": " << this -> getScore(i, 0) << endl;
    }
}

int Student::countStudent(){
    int count = 0;
    for (int i = 1; i < this -> student_no - 1; i++){
        if (this -> getScore(0,0) < this -> getScore(i,0)){
            count += 1;
        }
    }
    return count;
}