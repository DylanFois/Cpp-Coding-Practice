#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

struct Node { // For doubly linked list, there is a pointer to both the next node and the previous node
    int data;
    Node* prev; // points to previous node
    Node* next; // points to next node
};
// Advantage to doubly linked list is that now you can traverse both forwards and backwards through the list
// Disadvantage is increased memory usage due to having both a next pointer and a previous pointer

Node* createNewNode(int x);
void insertAtHead(int x, Node** head);
void insertAtTail(int x, Node* head);
void print(Node* head);
void reversePrint(Node* head);

int main(){

    Node* head = NULL;
    insertAtHead(4, &head);
    insertAtHead(7, &head);
    insertAtTail(9, head);
    insertAtHead(2, &head);
    insertAtHead(3, &head);

    print(head);
    reversePrint(head);

    return 0;
}

Node* createNewNode(int x){ // Since a lot of our functions rely on creating new nodes, we should create a function for it to reduce duplicate code
    Node* temp = new Node(); // Create a node on heap memory using new keyword, assign a local pointer "temp" to it which will be deleted when function call finishes
    temp->data = x; // Assign data value that was passed in through function parameter
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void insertAtHead(int x, Node** head){
    Node* temp = createNewNode(x); // Call createNewNode function to create a new node on the heap

    if(*head == NULL){ // If the head pointer is null, then the list is empty, so head can point to the new node we created
        *head = temp; // Point head to new node
        return;
    }
    // If head is not null, then it is already pointing to another node, so that node needs to be updated
    (*head)->prev = temp; // The current head nodes previous should now point to the new node as the new node is inserted at the start of the linked list 
    temp->next = *head; // the new nodes next should point to the node that head is currently pointing to because the new node is going infront of the previous first node
    *head = temp; // Head should now point to the new node
}

void insertAtTail(int x, Node* head){
    Node* temp = createNewNode(x); // Create new node

    while(head->next != NULL){ // Traverse to final node
        head = head->next;
    }
    head->next = temp; // The current final nodes next parameter should point to the newly created node
    temp->prev = head; // The newly created nodes previous parameter should point to the current final node
}

void print(Node* head){
    printf("Forward: ");
    while(head != NULL){ // Traversal logic, while head is not NULL, then print the data from that node
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reversePrint(Node* head){
    printf("Reverse: ");
    while(head->next != NULL){ // First we need to traverse to the final node
        head = head->next;
    }
    while(head != NULL){ // Then we can begin going backwards
        printf("%d, ", head->data); // Print the data from the node
        head = head->prev;  // Make head point to the previous node, loop continues to print data and set itself to previous node until it reaches the start
    }
    printf("\n");
}