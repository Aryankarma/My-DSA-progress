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


void insertathead(Node* &head, int data){
    // creating new node
    Node *temp = new Node(data);
    temp -> next = head; // connecting the temp node to the old node (head)
    head = temp;         // this head always has to connect to the first node (as we are inserting at head, newly generated node is the first node now)
}

void insertattail(Node *tail, int data){
    Node *temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void print(Node* &head){
    // creating a new pointer
    Node* current = head;

    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


int main(){

    // creating in heap memory
    Node* node1 = new Node(10);
    
    // cout << "Address " << node1->next << endl;
    // cout << "Data : " << node1->data << endl;

    Node *head = node1; 
    Node *tail = node1; 

    print(head);

    insertathead(head, 20);
    print(head);

    insertathead(head, 30);
    print(head);

    print(tail);

    insertattail(tail, 20);
    print(tail);

    insertattail(tail, 30);
    print(tail);


}