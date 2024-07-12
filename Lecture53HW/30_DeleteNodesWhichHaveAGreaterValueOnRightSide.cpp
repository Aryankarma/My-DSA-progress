// SINGLY LINKED LIST
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;   // integer data
    Node *next; // pointer variable "add" that stores the address of object

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertattail(Node *&tail, int data){
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head){
    Node *current = head;

    while (current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* deleteNodes(Node* head){
    Node *initial = new Node(0);
    initial->next = head;
    Node *headMain = initial;
    Node *curr = initial;
    Node *temp = NULL;

    while (curr->next != NULL && curr->next->next != NULL){
        if (curr->next->data < curr->next->next->data){
            temp = curr->next;
            curr->next = curr->next->next;
            cout << "temp data : " << temp->data << " ";
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return headMain->next;
}

int main(){
    Node *node = new Node(8);

    Node *head = node;
    Node *tail = node;

    insertattail(tail, 7);
    insertattail(tail, 8);
    insertattail(tail, 4);
    insertattail(tail, 5);
    insertattail(tail, 6);
    insertattail(tail, 2);
    insertattail(tail, 1);

    deleteNodes(head);
}