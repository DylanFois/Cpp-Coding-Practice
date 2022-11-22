#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stack>
using namespace std;
void arrayStack();
void push(int x, int A[], int* top, int size);
void pop(int A[], int* top);
int top(int A[], int top);
bool isEmpty(int top);
void reverse(char c[], int size);

int main(){
    arrayStack();
    
    return 0;
}

// Stack is last in, first out
// ie stack of plates, can only take the top plate out on a stack of plates
// It is a list with the restriction that insertion and deletion can be performed only from one end, called the top

// OPERATIONS
// Push - Push something to the top of the stack
// Pop - Delete something at the top of the stack
// Top - View the element at the top of stack
// Is Empty - boolean if the stack is empty or not
// ^^^ Time complexity for all is O(1)

// APPLICATIONS
// - Function calls / Recursion
// - Undo operation (by pushing the command we used to the stack)
// - Balanced parentheses {()}

// IMPLEMENTATIONS
// - Arrays
// - Linked lists

// OVERFLOW
// What happens if you have 10 elements in a stack using an array of 10, and you try to push? This will result in an overflow
// To fix, we can create a new array and copy all the existing elements into it, plus the one you tried to push. This is O(n) because every element has to be copied into the new array
// New push method would be O(1) best case (ie no overflow), and O(n) worst case (need to create new array for overflow and put all of n elements into it), average case is O(1)

void arrayStack(){
    int A[10]; // Declare an int array
    int size = sizeof(A)/sizeof(A[0]);
    int top = -1; // initialise a variable called top to store the index of the top element, -1 because the stack is empty

    int x;
    // for(int i = 0; i<9; i++){
    //     printf("Enter number\n");
    //     scanf("%d", &x);
    //     push(x, A, &top);
    // }

    push(5, A, &top, size);
    push(8, A, &top, size);
    push(2, A, &top, size);
    push(4, A, &top, size);
    pop(A, &top);

    for(int i = 0; i<top; i++){
        printf("%d, ", A[i]);
    }

}

void push(int x, int A[], int* top, int size){ // Needs the array (will be a pointer), also needs a pointer to top, as the function is void, so use the pointer to adjust top in main
    if(*top + 1 == size){
        printf("Error: Stack overflow\n");
        return;
    }
    *top = *top+1; // Increment top so it points to the next empty element
    A[*top] = x; // Store the value at top, top will now be an index marker for this element
}

void pop(int A[], int* top){ // Don't need A[] if you dont delete A[*top]
    // A[*top] = 0; Dont need to set the element to 0 or null as the stack only goes as high as top, so next time something is pushed, it will be changed anyway
    if(*top == -1){return;} 
    *top = *top - 1; // Decrement top to store the index of the next highest element ONLY if top is not already -1, meaning the stack is empty
}

int top(int A[], int top){ // Top simply returns the top element, don't need pointer to top as we arent manipulating the value of top, A[] is already a pointer
    return A[top];
}

bool isEmpty(int top){ // Don't need pointer to top as we arent manipulating the value of top
    if(top < 0){return true;}  // If top is -1, then top is empty. If it is 0 or greater, then it is storing the index of an element and is not empty
    return false;
}

void reverse(char c[], int size){
    stack<char> S; // Created stack of characters
}