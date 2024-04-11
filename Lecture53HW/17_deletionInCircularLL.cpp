// SINGLY LINKED LIST
#include<bits/stdc++.h>
using namespace std;

/* Problem Statement -  Deletion In Circular Linked List

    You are given a Circular Linked List of integers, and an integer, 'key'.

    You have to write a function that finds the given key in the list and deletes it. If no 
    such key is present, then the list remains unchanged.

    For Example :
    This is a visualization of the Circular Linked List, represented by:
    1 2 3 4 5 -1

*/

// Link to codingNinjas [https://www.naukri.com/code360/problems/deletion-in-circular-linked-list_630409?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker]

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

int main(){       
          
    Node* node1 = new Node(10);
          
    Node *head = node1;
    Node *tail = node1;

    insertattail(tail, 20);
    insertattail(tail, 30);
    insertattail(tail, 40);

    tail->next = head; // uncomment to make it circular

    print(head);
    
}