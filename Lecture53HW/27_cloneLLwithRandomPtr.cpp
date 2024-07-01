#include<bits/stdc++.h>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *ran;

    Node(int value){
        this->data = value;
        this->next = NULL;
        this->ran = NULL;
    }
};

void print(Node* &head){
    Node *current = head;
    
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;    
    }
    cout << endl;
}

void printRandom(Node* &head){
    Node *current = head;
    
    while(current != NULL){
        if(current->ran){
            cout << current->data << " -> " << current->ran->data << " | ";
        }
        current = current->next;
    }
    cout << endl;
}

void insertattail(Node* &tail, int data){
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void cloneLL(Node* &head){
    Node *clonedLL = new Node(0);
    Node *temp = head;
    Node *cloneTail = clonedLL;
    Node *cloneHead = clonedLL;
    map<Node*, Node*> mapping;

    // clone next from original
    while(temp != NULL){
        insertattail(cloneTail, temp->data);
        temp = temp->next;
    }

    // map both the LL
    temp = head;
    while(temp != NULL){
        mapping[temp] = cloneHead->next;
        temp = temp->next;
        cloneHead = cloneHead->next;
    }

    temp = head;
    cloneHead = clonedLL->next;
    while(temp != NULL){
        if(temp->ran){
            cloneHead->ran = mapping[temp->ran];
        }
        temp = temp->next;
        cloneHead = cloneHead->next;
    }

    temp = head;
    cloneHead = clonedLL->next;
    printRandom(temp);
    printRandom(cloneHead);
}

int main(){
    Node* LL = new Node(1);

    Node* head = LL;
    Node* tail = LL;

    insertattail(tail, 2);
    insertattail(tail, 3);
    insertattail(tail, 4);
    insertattail(tail, 5);

    head->ran = head->next->next; // (1,3)tail
    head->next->ran = head; // (2,1)
    head->next->next->ran = tail; // (3,5)
    head->next->next->next->ran = tail; // (4,5)
    tail->ran = head->next; // (5,2)

    // printRandom(head);
    cloneLL(head);
}