#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertNode(Node** head, int x, int pos);
void deleteNode(Node** head, int pos);
void reverseNode(Node** head);
void printNode(Node* head);

int main(){

    Node* head = NULL;

    int x,y,pos;
    printf("Num of elements?\n");
    scanf("%d", &y);
    for(int i=0; i<y; i++){
        printf("Enter number\n");
        scanf("%d", &x);
        printf("Enter position\n");
        scanf("%d", &pos);
        insertNode(&head, x, pos);
        printNode(head);
    }

    printf("Num of elements?\n");
    scanf("%d", &y);
    for(int i=0; i<y; i++){
        printf("Enter node to delete");
        scanf("%d", &pos);
        deleteNode(&head, pos);
        printNode(head);
    }

    reverseNode(&head);
    printNode(head);

    return 0;
}

void insertNode(Node** head, int x, int pos){
    Node* temp = new Node();
    temp->data = x;
    if(pos==1 || *head == NULL){
        temp->next = *head;
        *head = temp;
        return;
    }
    Node* temp1 = *head;
    for(int i = 0; i<pos-2 && temp1->next != NULL; i++){
        temp1=temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void deleteNode(Node** head, int pos){
    Node* temp = *head;
    if(pos==1){
        *head = temp->next;
        free(temp);
        return;
    }
    for(int i=0;i<pos-2;i++){
        temp = temp->next; 
    } // temp = pos-1
    Node* temp1 = temp->next; // temp1 = pos
    temp->next = temp1->next; // pos-1 = pos+1
    free(temp1);
}

void reverseNode(Node** head){
Node* current = *head;
Node* prev = NULL;
Node* next;

while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
}
*head = prev;
}

void printNode(Node* head){
    while(head != NULL){
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}