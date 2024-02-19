// SINGLY LINKED LIST
#include<bits/stdc++.h>
using namespace std;

/*  problem statement - Deleting and Adding the last node

    You are provided with a singly linked list, all you have to do is to delete the last node of the 
    linked list and add it to the front of the linked list.

    sample input:
    2 5 3 11 1 -1
    
    sample output: 
    1 2 5 3 11 -1
*/

// link to codingninjas [https://www.codingninjas.com/studio/problems/deleting-and-adding-the-last-node_1170051?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker]

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

Node* removeLastAddFirst(Node* head){
    // go to the last node, get the data add it into a new LL

	if(head == NULL || head->next == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = head;
    Node* temphead = head;

    while(curr != NULL){
        if(curr->next == NULL){
            Node* temp = new Node(curr->data);
            prev->next = NULL;
            delete curr;
            temp->next = temphead;
            return temp;
        }
        prev = curr;
        curr = curr->next;
    }

};

int main(){       
          
    Node* node1 = new Node(2);        
          
    Node *head = node1;
    Node *tail = node1;


    insertattail(tail, 5);
    insertattail(tail, 3);
    insertattail(tail, 11);
    insertattail(tail, 1);

    print(head);

    Node* printthishead = NULL;

    printthishead = removeLastAddFirst(head);

    print(printthishead);

}