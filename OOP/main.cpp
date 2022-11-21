#include <iostream>
#include "IEmployee.cpp"
#include "Employee.cpp"
#include "Developer.cpp"
#include "Teacher.cpp"

int main(){

    Developer d("Dylan", "Bruh", 22, "C++");
    d.fixBug();
    d.AskForPromotion();
    d.getName();

    Teacher t("Bruhnda", "Qwop Inc", 32, "Math");
    t.Introduce();
    t.teachSubject();
    t.AskForPromotion();

    d.Work(); // Developer.work();
    t.Work(); // Teacher.work();

    Employee* e1 = &d; // Employee pointer e1 pointing to memory address of Developer d (Developer is an employee so an employee pointer can be used)
    Employee* e2 = &t;

    e1->Work(); // If virtual keyword is not used on employee classes work function, then this will point to Employee class work, rather than the subclass Work function
    e2->Work(); // If virtual keyword in parent class work function, then this will execute sub class function rather than parent class function
                // If the subclass does not have a Work function, then the parent class function will be used
    return 0;
}