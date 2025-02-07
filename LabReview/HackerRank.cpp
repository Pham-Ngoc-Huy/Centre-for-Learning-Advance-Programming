#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person{
    protected:
        string name;
        int age;
    public:
        static int id_professor;
        static int id_student;
        Person() : name(""), age(0) {} // Constructor mặc định
        Person(const string& name_, const int& age_): name(name_), age(age_){};
        virtual void getdata() = 0;
        virtual void putdata() = 0;
        virtual ~Person(){};
};
int Person::id_professor = 0;
int Person::id_student = 0;
class Professor : public Person{
    protected:
        int publications;
        int cur_id;
    public:
        //constructor
        Professor() : Person(), publications(0), cur_id(++id_professor) {} // Constructor mặc định

        Professor(const string& name_, const int& age_, const int& publications_): Person(name_, age_), publications(publications_){
            cur_id = ++id_professor;
        };
        //functions members
        void getdata() override{
            cin>> name >> age >> publications;
        }
        void putdata() override{
            cout<< name << " " << age << " " << publications << " " << cur_id <<endl;
        }
        virtual ~Professor(){};
};
class Student : public Person{
    protected:
        int mark[6]; // array
        int cur_id;
    public:
        // constructor
        Student() : Person(), cur_id(++id_student) { fill(begin(mark), end(mark), 0); }
        Student(const string& name_, const int& age_, int mark_[6]): Person(name_, age_){
            for(int i=0;i<6;i++){
                mark[i] = mark_[i];
            }
            cur_id = ++id_student;
        };
        //function members
        void getdata() override {
            cin >> name >> age;
            for (int i = 0; i < 6; i++) {
                cin >> mark[i];
            }
        };
        int sumofmark(){
            int fullmark = 0;
            for (int i = 0; i < 6; i++)
                fullmark += mark[i];
            return fullmark;
        }
        void putdata() override{
            cout << name << " " << age << " " << sumofmark() << " " << cur_id << endl;
        }        
        virtual ~Student(){};

};
int main(){

    int n, val;
    cin>>n;
    vector<Person*>per;

    for(int i = 0;i < n;i++){

        cin>>val;
        if (val == 1) {
            per.push_back(new Professor); // Allocate new Professor object
            } else {
            per.push_back(new Student);   // Allocate new Student object
            }

            per[i]->getdata(); // Get the data from the user
    }
    for (int i = 0; i < n; i++) {
        per[i]->putdata(); // Print the required output for each object
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        delete per[i];
    }
    return 0;

}


