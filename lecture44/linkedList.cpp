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

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};


void insertathead(Node* &head, int data){
    // creating new node
    Node *temp = new Node(data);
    temp -> next = head; // connecting the temp node to the old node (head)
    head = temp;         // this head always has to connect to the first node (as we are inserting at head, newly generated node is the first node now)
}

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

void insertatposition(Node* &head, Node* &tail ,int position, int data){
    // creating a pointer
    Node* pointer = head;
    int count = 1;

    if(position == 1){
        insertathead(head, data);
        return;
    }
    
    while(count < position-1){
        pointer = pointer->next;
        count++;
    }

    // if it's the last position
    if(pointer->next == NULL){
        insertattail(tail, data);
        cout << "inserting at tail " << endl;
        return;
    }

    // creating a new node
    Node* newNode = new Node(data);

    newNode->next = pointer->next;
    pointer->next = newNode;
};

void deleteNode(Node* &head, Node* &tail, int position){
    int count = 1;
    Node* pointer = head;
    Node* current = head;

    // if removing the very first node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    while(count < position-1){
        // pointer = pointer->next;
        pointer = current;
        current = current->next;
        count++;
    }

    
    // cout << pointer->data << endl;
    // cout << current->data << endl;
    // current = current->next;
    // cout << current->data << endl;
    pointer->next = current->next;
    current->next = NULL;
    // tail->next = current->next;
    delete current;
};

         
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

    insertathead(head, 40);
    print(head);

    insertathead(head, 50);
    print(head);

    // print(tail);

    // insertattail(tail, 20);
    // print(tail);

    // insertattail(tail, 30);
    // print(tail);

    // insertattail(tail, 40);
    // print(tail);


    // creating insertatposition function
    insertatposition(head, tail, 1, 60);
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
        
    deleteNode(head, tail, 6);
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    
}