#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* temp  = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
};

void printtail(Node* &tail){
    Node *temp = tail;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
};

void getLength(Node *head){
    Node *ptr = head;
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;        
    }
    cout << count << endl;
};

void insertathead(int data, Node* &head, Node* &tail){
    
    // if(head == NULL){
    //     Node* temp = new Node(data);
    //     head = temp;
    //     tail = temp;
    // }else{
        Node *temp = new Node(data);

        // (temp) |prev| data |next|   (head) |prev| data |next|

        temp->next = head;  // connecting temp node's next with head node
        head->prev = temp;  // connecting previous node's prev with new  node
        head = temp;        // updating head
    // }
};

void insertattail(int data, Node* &tail, Node* &head){

    // if(tail == NULL){
    //     Node* temp = new Node(data);
    //     tail = temp;
    //     head = temp;
    // }else{
        Node *temp = new Node(data);

        // (tail) |prev| data |next|    (temp) |prev| data |next|

        tail->next = temp;  // connect tail's next to temp 
        temp->prev = tail;  // connect temp's prev to tail
        tail = temp;        // update tail 
    // }
};

int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    getLength(head);
    insertathead(20, head, tail);
    print(head);
    insertathead(30, head, tail);
    print(head);
    insertathead(40, head, tail);
    print(head);

    insertattail(100, tail, head);
    print(head);
    insertattail(200, tail, head);
    print(head);
    insertattail(300, tail, head);
    print(head);
}