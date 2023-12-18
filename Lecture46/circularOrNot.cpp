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

bool checkCircular(Node* &head){
    Node* current = head->next;

    // if 0 elements are there
    if(head == NULL){
        return true;
    }

    // if there is 1 node
    if(head->next == head){        
        return true; // circular with 1 node only
    }else if(head->next == NULL){
        return false; // not a circular LL
    }

    while(current != NULL && current != head){
        if(current->next == NULL){
            // it is not a circular LL
            return false;
        }else if(current->next == head){
            // it is a circular LL
            return true;
        }else{
            current = current->next;
        }
    }

    return true;
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
    // insertattail(tail, 3);
    // insertattail(tail, 4);
    // insertattail(tail, 5);
    // insertattail(tail, 6);

    cout << checkCircular(head) << endl;

}