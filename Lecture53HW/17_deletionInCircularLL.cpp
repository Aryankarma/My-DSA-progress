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

    Node* ptr = head;

    cout << head->data << " ";
    head = head->next;

    while(head != ptr){
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

Node* removeElement(Node* head, int key){

    // better than 66%
    // if(head == NULL || head->next == NULL){
    //     return NULL;
    // }

    // better than 99%
    if(head == NULL){
        return NULL;
    }

    if(head->next == head && head->data == key){
        return NULL;   
    }

    Node* temp = head->next;
    int count = 1;

    while(temp != head){ // get's the exact number of elements in cicrular list
        count++;
        temp = temp->next;
    }

    Node* prev = nullptr;
    Node* curr = head;

    if(head->data == key){
        prev = curr->next;
        while(prev->next->data != head->data){
            prev = prev->next;
        }
        prev->next = curr->next;
        head = head->next;
    }else{            
        while( (curr->data != key) && (count > 0) ){
            prev = curr;
            curr = curr->next;
            count--;
        }

        if(curr->data == key){
            prev->next = curr->next;
        }
    }
    return head;
};

int main(){       
          
    Node* node1 = new Node(1);
          
    Node *head = node1;
    Node *tail = node1;

    insertattail(tail, 2);
    insertattail(tail, 3);
    insertattail(tail, 4);
    insertattail(tail, 5);

    tail->next = head; // uncomment to make it circular

    head = removeElement(head, 50);

    print(head);
}