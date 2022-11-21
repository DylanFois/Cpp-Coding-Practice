using namespace std;
#include <string>

class IEmployee{ // Abstract class, holds only what the class can do, not how it does it (eg empty methods), employee inherits this class and must implement the methods defined
    virtual void AskForPromotion()=0; // virtual keyword and =0 means it is a purely abstract function, any class that signs this contract HAS to implement the AskForPromotion function
                                // =0 means it is PURE virtual function, MUST be overrided in derived class. without =0 means its a virtual function, the abstract class needs an implementation too
};                              // and derived class can choose to override the abstract implementation