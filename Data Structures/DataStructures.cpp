#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

struct Node{ // Define the node structure using struct
        int data; // Needs data, can be any type
        Node* next; // Needs Node pointer to hold the address of the next node (can be called anything, typically link or next)
    };

void linkedListImplementation();
void insertNodeBeginning(Node** head, int x);
void insertNodeNth(Node** head, int x, int pos);
void deleteNodeNth(Node** head, int pos);
void reverseLinkedList(Node** head);
void printNode(Node* head);
void printRecursion(Node* p);
int nodeRecursion(Node* p);
bool isPalindrome(Node* head);

int main(){
    Node* head = NULL; // empty list
    printf("How many numbers to insert?\n");
    int n, x, pos;
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter the number: \n");
        scanf("%d", &x);
        printf("Enter the position: \n");
        scanf("%d", &pos);
        insertNodeNth(&head, x, pos);
        printNode(head);
    }

    int test = nodeRecursion(head);
    cout << test;

    //reverseLinkedList(&head);
    //printNode(head);
    //printRecursion(head);

    return 0;
}

void linkedListImplementation(){
    struct Node{ // Define the node structure using struct
        int data; // Needs data, can be any type
        Node* link; // Needs Node pointer to hold the address of the next node
    };

    Node* A;
    A = NULL;

    Node* temp9 = (Node*)malloc(sizeof(Node)); // use malloc to allocate a block of memory the size of a Node, typecast it to Node pointer
    free(temp9); // not part of code, freeing the node since we wont be using it
    // OR
    Node* temp = new Node(); // This is preferred over malloc ^^

    temp->data = 2; // Access and edit node variables
    temp->link = NULL;

    A = temp; // A is now the pointer to the head node, temp is only used to manipulate the nodes

    // INSERT NEW NODE AT END
    temp = new Node(); // Create the node that needs to be added at the end
    temp->data = 4;    // Fill in its data 
    temp->link = NULL; // link = NULL as it is the final node and does not point to another node 

    Node* temp1 = A; // Create new temporary pointer from A
    while(temp1->link != NULL){ // If the link variable is not null, then it will set its own memory address as the link, meaning it now points to the next node. This is done until it reaches the final node
        temp1 = temp1->link;    // which is the node with a memory address (link) that is NULL.
    } // This is also traversal logic for linked list
    temp1->link = temp; // temp1 points to final node, temp is the new node we created
                        // the link of the final node (temp1) = the memory address of the new node, therefore adding the new node (temp) to the linked list 
}

void insertNodeBeginning(Node** head, int x){ // Needs to be pointer to pointer ** as if you just pass in head, you are passing the memory address that head stores, which is the first node, rather than head itself.
    Node* temp = new Node(); // Create new node
    temp->data = x;
    temp->next = *head; // Assuming 1 node already in list, head points to the first block. Therefore temp->next = head means the new nodes next value is the memory address of the node head was already pointing to
    *head = temp; // Now make head point to the new node, since the new node now points to the node that head used to point to

    // Pointer to pointer, *head = head in main's memory address which is the address to the next node, so editing that address changes main() head.
}

void insertNodeNth(Node** head, int x, int pos){
    Node* temp = new Node();
    temp->data = x;
    if(pos==1 || *head == NULL){ //if position is 1 or head is null, then insert node at pos1 by making temp->next equal to *head, then if head points to nothing then next is null,
        temp->next=*head;        // otherwise if there is a node at pos1, then *head points to it and we then make temp->next equal to the memory address of the node that *head points to.
        *head=temp; // update *head to point to the new node
        return;
    }

    Node* temp1 = *head;
    for(int i=0;i<pos-2 && temp1->next != NULL;i++){ // pos=3, i=0 (loop hasnt run): temp1 points to 1st node. i=1 (loop run once): temp1 points to 2nd node, therefore has to be pos-2
        temp1=temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void deleteNodeNth(Node** head, int pos){
    Node* temp1 = *head;
    if(pos==1){ // if deleting first node
        *head = temp1->next; // head and temp1 currently point to same thing, so set head to temp1->next so head now points to 2nd node (and that node becomes 1st node)
        free(temp1); // temp1 points to 1st node still, so free it from heap
        return;
    }
    for(int i=0;i<pos-2;i++){
        temp1 = temp1->next; // pos-1 node
    }
    Node* temp2 = temp1->next; // temp2 = pos node | CANNOT do temp2 = temp2->next, because this is pos+1 and when you free this, you are freeing pos+1 node from memory
    temp1->next = temp2->next; // temp1 next (pos-1) = pos+1 node
    free(temp2); // remove this node from heap (temp2 is a pointer to the node so it is freeing the node)

    // FOR MAIN
    // printf("How many numbers to delete?\n");
    // scanf("%d", &n);

    // for(int i=0;i<n;i++){
    //     printf("Enter the position: \n");
    //     scanf("%d", &pos);
    //     deleteNodeNth(&head, pos);
    //     printNode(head);
    // }
}

void reverseLinkedList(Node** head){
    Node* current = *head;
    Node* prev = NULL;
    Node* next;

    while(current != NULL){
        next = current->next; // store the address to the next node in "next"
        current->next = prev; // current->next is overwritten with the previous nodes address
        prev = current; // previous now points to current node, as current will point to the next node in the next loop
        current = next; // current now points to the next node
    }
    *head = prev; // head still points to the original first node which is now the last, so we need to update head to point to the new starting node
}

void printNode(Node* head){ // head here is a pointer to main() head, therefore we can iterate printNode() head without affecting main() head
    printf("List:\n");      // and also do not need to create a temporary pointer like Node* temp to refer to head.
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printRecursion(Node* p){
    if(p != NULL){
        printf("%d, ", p->data);
        printRecursion(p->next);
    }
}

int nodeRecursion(Node* p){
    if(p->next != NULL){
        nodeRecursion(p->next, (p->data));
    }
    return p->data;
}

bool isPalindrome(Node* head){
    Node* temp = head;

}

// O(1) constant time to access an element in an array because to access an element, you do A[x] and this gives you the memory address
// for that element.

// For linked list, it is O(n) because to access a node, you need to go through every node before it to get the next memory address
// O notation uses worst case scenario so it is O(n), as if you are trying to access the last node, then you have to go through
// every element before it.


// Space requirements

// ARRAY
// Arrays are fixed sizes, can have empty space in the array
// an array of 7 elements has a size of 7 * 4 bytes per integer = 28 bytes
// If lots of memory used, may have a problem where there is not a large enough block of memory for an array

// ~ INSERT AT BEGINNING
//   O(n) as we need to move every element in the array over to insert at the beginning

// ~ INSERT AT END   
//   O(1) if not full (A[x] = 5)
//   O(n) if full, as a new array needs to be created and all elements copied into it

// ~ INSERT AT i-th POSITION
//   O(n) as you need to shift over elements in the array


// LINKED LIST
// Linked list does not have unused memory, but uses extra memory to store the memory address of the next node (pointer variable)
// a linked list of 7 elements has a size of 7 * (4 bytes for integer + 4 bytes for pointer variable) = 7 * 8 = 56 bytes
// if the data portion of the linked list is larger (eg 16 bytes, + 4)
// Can be created even if no large block of memory

// ~ INSERT AT BEGINNING
//   Just make a new node, and have the memory address stored in that node point to the original first variable, no need to move every element over, therefore O(n)

// ~ INSERT AT END
//   O(n) as the whole list has to be traversed and the last node updated to point to the new last node

// ~ INSERT AT i-th POSITION
//   O(n) as you have to traverse the nodes to update them and add the new one