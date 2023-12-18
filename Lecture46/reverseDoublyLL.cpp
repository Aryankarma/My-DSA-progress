#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* prev;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node* &head){
    Node* ptr = head;

    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;
};

void reverse(Node* &head){
    Node* element = NULL;
    Node* current = head;
    Node* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = element;
        element = current;
        current = next;
        head = element;
    };

    print(head);
};

void insertattail(Node* &tail, int data){
    Node* temp = new Node(data);

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
};

int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertattail(tail, 2);
    insertattail(tail, 3);
    insertattail(tail, 4);
    insertattail(tail, 5);
    insertattail(tail, 6);

    // before reverse
    print(head);

    // after reverse
    reverse(head);

}