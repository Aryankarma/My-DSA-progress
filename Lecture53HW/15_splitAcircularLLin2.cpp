// SINGLY LINKED LIST
#include<bits/stdc++.h>
using namespace std;

/* Problem Statement - 

    You are given a circular linked list having N number of nodes, where N is even. You have to split this 
    linked list into two equal-sized circular linked lists.
    Here splitting means you have to make two separate circular linked lists, one for the first N/2 nodes
    and one for the last N/2 nodes.

    For Example -
    Let the circular linked list be 1, 2, 3, 4. We have to split this into two equal-sized circular linked 
    lists.
*/

// Link to codingNinjas [https://www.naukri.com/code360/problems/split-a-circular-linked-list_1071003?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker]

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

void splitIt( Node* head ){
    Node* slow = head;
    Node* temp = NULL;
    Node* fast = head->next;
    bool checkTrue = false;

    while( slow != fast ){
        slow = slow->next;
        fast = fast->next;

        checkTrue = !checkTrue;

        if( fast->next != head ){
            fast = fast->next;
        }

        if( checkTrue ){
            if( temp == NULL ){
                temp = head;
            }else{
                temp = temp->next;
            }
        }
    }

    slow->next = temp->next; // left list
    temp->next = head; // right list
        
};

int main(){       
          
    Node* node1 = new Node(1);
          
    Node *head = node1;
    Node *tail = node1;

    insertattail(tail, 2);
    insertattail(tail, 3);
    insertattail(tail, 4);
    insertattail(tail, 5);
    insertattail(tail, 6);
    insertattail(tail, 7);
    insertattail(tail, 8);
    insertattail(tail, 9);
    insertattail(tail, 10);
    insertattail(tail, 11);
    insertattail(tail, 12);

    tail->next = head;
    splitIt(head);
}