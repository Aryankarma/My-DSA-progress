// SINGLY LINKED LIST
#include<bits/stdc++.h>
using namespace std;

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
    Node* fast = head->next;


    while( slow != NULL ){
        slow = slow->next;
        fast = fast->next;
        
        if( fast->next != head ){
            fast = fast->next;
        }else if( fast == head ){
            
        }
    }

}

int main(){       
          
    Node* node1 = new Node(10);        
          
    Node *head = node1;
    Node *tail = node1;


    insertattail(tail, 20);
    insertattail(tail, 30);
    insertattail(tail, 60);
    insertattail(tail, 50);
    insertattail(tail, 40);

    tail->next = head;

    splitIt(head);


}