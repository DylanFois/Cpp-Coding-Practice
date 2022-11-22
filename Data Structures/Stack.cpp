#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

class Stack{ // Can create your own stack class like so
private:
    char A[101];
    int top;

public:
    void push(int x);
    void pop();
    int top();
    bool isEmpty();
};