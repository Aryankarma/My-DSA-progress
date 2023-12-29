#include<bits/stdc++.h>
using namespace std;

// splitting a circular linked list into 2 halves

class Node{
    public:
    Node* next;
    int data;

    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};

void insertattail(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);

    tail->next = temp;
    tail = temp;

    tail->next = head;
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
        if(temp == head){
            break;
        }
    }
    cout << endl;
}

void splitList(Node* &head){
    Node* slow = head;
    Node* fast = head->next;


    while(fast != head && fast->next != head){

        slow = slow->next;
        fast = fast->next;
        if(fast->next != head){
            fast = fast->next;
        }
    }

    cout << "head: " << head->data << endl;
    cout << "Slow: " << slow->data << endl;    
    cout << "fast: " << fast->data << endl << endl;

    Node* temp = head;
    Node* temp2 = slow;

    Node* listone = head;
    Node* listtwo = slow;

    Node* tempnodeone = listone;
    Node* tempnodetwo = listtwo;
    Node* nodeone = listone;
    Node* nodetwo = listtwo;

    while(temp != slow){
        tempnodeone->next = temp->next;        
        tempnodetwo->next = temp2->next;

        cout << "tempnodeone: " << tempnodeone->data << endl;    
        cout << "tempnodetwo: " << tempnodetwo->data << endl;   

        tempnodeone = tempnodeone->next;
        tempnodetwo = tempnodetwo->next;
        
        cout << "tempnodeone next: " << tempnodeone->data << endl;    
        cout << "tempnodetwo next: " << tempnodetwo->data << endl;   

        temp = temp->next;
        temp2 = temp2->next;
    }

    cout << endl;

    tempnodeone->next = NULL;
    tempnodetwo->next = NULL;

    cout << "printing listone : " << endl;
    print(nodeone);
    cout << "printing listtwo : " << endl;
    print(nodetwo);

}

int main(){
    
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertattail(head, tail, 20);
    insertattail(head, tail, 30);
    insertattail(head, tail, 40);
    insertattail(head, tail, 50);
    insertattail(head, tail, 60);
    insertattail(head, tail, 70);

    print(head);

    splitList(head);



}