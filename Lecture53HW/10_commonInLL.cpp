// SINGLY LINKED LIST
#include<iostream>
#include <bits/stdc++.h>
#include <stddef.h>
using namespace std;

/* Problem statement
    You are given two linked lists L1 and L2 which are sorted in ascending order. You have to make a linked list 
    with the elements which are present in both the linked lists and are present in ascending order.

    Example:-
    L1 = 1->2->3->4->7
    L2 = 2->4->6->7

    ANSWER:- The answer should be 2->4->7 because 2,4, and 7 are present in both the linked lists
*/

class Node{
    public:
    int data;   // integer data
    Node *next;  // pointer variable "add" that stores the address of object

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


void insertattail(Node* &tail, int data){
    Node *temp = new Node(data);    
    tail -> next = temp;
    tail = temp;
}

void print(Node* &head){
    Node* current = head;

    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
Node* intersect_ll(Node* L1, Node *L2){
    Node* finalLL = new Node(0);

    Node* temptail = finalLL;
    Node* ptr1 = L1;
    Node* ptr2 = L2;

    while((ptr1 != NULL) && (ptr2 != NULL)){
        if(ptr1->data < ptr2->data){
            ptr1 = ptr1->next;
        }else if(ptr2->data < ptr1->data){
            ptr2 = ptr2->next;
        } else {
            insertattail(temptail, ptr1->data);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    
    return finalLL->next;
}

int main(){
          
    Node* node1 = new Node(10);
    Node* node2 = new Node(11);
          
    Node *head = node1;
    Node *tail = node1;
    Node *head2 = node2;
    Node *tail2 = node2;

    insertattail(tail, 20);
    insertattail(tail, 20);
    insertattail(tail, 20);

    insertattail(tail2, 20);
    insertattail(tail2, 30);
    insertattail(tail2, 40);

    Node* result = intersect_ll(node1, node2);   
    print(result); 
}