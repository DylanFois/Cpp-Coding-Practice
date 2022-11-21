using namespace std;
#include <string>

class Developer:public Employee{ // Class developer inherits from employee class, need public keyword to access the employee methods in main by saying developer.askForPromotion();
private:
    string programmingLanguage; // This is unique to developer, as an employee does not need a programming language if they arent a developer (eg they are marketing)

public:
    Developer(string Name, string Company, int Age, string programmingLanguage) // Still include all the variables inherited from employee in constructor
        :Employee(Name, Company, Age){  // Pass the variables to the Employee constructor
        this->programmingLanguage = programmingLanguage; // Set the variables unique to Developer in the developer constructor
    }

    void fixBug(){
        cout << Name << " fixed bug using " << programmingLanguage << endl; // Can access "Name" variable because it is protected in Employee class, meaning sub class can access it as well
    }

    string getProgrammingLanguage(){
        return programmingLanguage;
    }

    void setProgrammingLanguage(string programmingLanguage){
        this->programmingLanguage = programmingLanguage;
    }

    void Work(){
        cout << Name << " is writing " << programmingLanguage << " code" << endl; 
    }
};