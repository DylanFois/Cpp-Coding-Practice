using namespace std;
#include <string>

class Teacher:public Employee{
    string Subject;

public:
    Teacher(string Name, string Company, int Age, string Subject) // Need name, company, age
        :Employee(Name, Company, Age){ // Pass name, company, age into employee constructor
            this->Subject = Subject;
        }    

    void teachSubject(){
        cout << Name << " is teaching " << Subject << endl;
    }

    void Work(){
        cout << Name << " is teaching " << Subject << endl;
    }
};