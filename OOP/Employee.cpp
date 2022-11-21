using namespace std;
#include <string>

class Employee:IEmployee{
protected: // ENCAPSULATION: Only the Employee class can access the variables, inaccessible to other classes and cannot be manipulated by them // Protected means subclass can access the variables as well
    string Name;
    string Company; // Class variables that define what an employee class is
    int Age;        // these are all private by default

public: // Allows other classes to access the methods underneath
    Employee(string Name, string Company, int Age){ // Constructor normally should be public, takes values and assigns it to object
        this->Name = Name;
        this->Company = Company;
        this->Age = Age;
    }

    void setName(string Name){ // Other classes should not be allowed to directly access class variables
        this->Name = Name;     // So we use a setter to set the class variable 
    }

    string getName(){ // Other classes should not be allowed to access class variables directly
        return Name;  // So we use a getter to return the value to the other class  
    }

    void setCompany(string Company){
        this->Company = Company;
    }

    string getCompany(){
        return Company;
    }

    void setAge(int Age){
        this->Age = Age;
    }

    int getAge(){
        return Age;
    }

    void AskForPromotion(){ // This is an implementation of the function in the abstract class employee, must be included in this class or it will not work
        if(Age>30){
            cout << Name << " promoted" << endl;
        }else{
            cout << Name << " not promoted" << endl;
        }
    }

    void Introduce(){
        //printf("Name: %s, Company: %s, Age: %d\n", Name, Company, Age);
        cout << Name << endl;
        cout << Company << endl;
        cout << Age << endl;
    }

    virtual void Work(){ // Using virtual keyword, can make it a polymorphic function
        cout << Name << " is checking emails, task backlog, performing tasks" << endl;
    }
};