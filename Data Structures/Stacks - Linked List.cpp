#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void nodeStack();
void push(int x, Node** top);
void pop(Node** top);
int top(Node* top);
bool isEmpty(Node* top);

int main(){
    nodeStack();
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
// For linked list, inserting at tail would mean O(n), as you have to traverse the whole linked list to get to the end to add and remove elements
// So instead we use the head

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

// REVERSING LINKED LISTS USING STACKS
// Iterative solution is Time O(n), Space O(1) (need 3 pointers always, current, previous, next)
// Recursive solution is Time O(n), Space O(n) (because the call stack is a stack and therefore n recursive calls) (Implicit stack)

void nodeStack(){
    Node* top = NULL;
    push(5, &top);
}

void push(int x, Node** top){
    Node* temp = new Node(); // Create new node
    temp->data = x; // Set the new nodes data as the variable passed into push
    temp->next = *top; // Make new nodes next parameter point to the node top was previously pointing to
    *top = temp; // Make top point to the new node
}

void pop(Node** top){
    if (*top == NULL){return;} // If top is already pointing to NULL, then stack is empty

    Node* temp = *top; // Create temp pointer to hold the block to be deleted
    *top = (*top)->next; // Make top point to the next node
    delete temp; // Free the memory that the old block used
}

int top(Node* top){
    return top->data;
}

bool isEmpty(Node* top){
    if(top == NULL){return true;}
    return false;
}