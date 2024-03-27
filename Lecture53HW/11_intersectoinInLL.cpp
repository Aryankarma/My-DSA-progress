// SINGLY LINKED LIST
#include<bits/stdc++.h>
#include<map>
using namespace std;

/* Problem statement
    You are given two Singly Linked Lists of integers, which may have an intersection point.
    Your task is to return the first intersection node. If there is no intersection, return NULL.

    Example:-
    The Linked Lists, where a1, a2, c1, c2, c3 is the first linked list and b1, b2, b3, c1, c2, c3 is 
    the second linked list, merging at node c1.

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
Node* findIntersection(Node* L1, Node *L2){
    Node* ptr1 = L1;
    Node* ptr2 = L2;

    map<Node*, bool> checkSeen; 
    
    while(ptr1 != NULL){
        checkSeen[ptr1] = true;
        ptr1 = ptr1->next;
    }

    while(ptr2 != NULL){
        if(checkSeen.find(ptr2) != checkSeen.end()){
            return ptr2;
        }
        ptr2 = ptr2->next;
    }

    return NULL;
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

    Node* result = findIntersection(node1, node2);   
    cout << result->data << endl; 
}