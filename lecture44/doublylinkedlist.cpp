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
    ~Node(){
        int value = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory free with data : " << value << endl;
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
    
    // if list is empty
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }else{
        Node *temp = new Node(data);

        // (temp) |prev| data |next|   (head) |prev| data |next|

        temp->next = head;  // connecting temp node's next with head node
        head->prev = temp;  // connecting previous node's prev with new  node
        head = temp;        // updating head
    }
};

void insertattail(int data, Node* &tail, Node* &head){

    // if list is empty
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }else{
        Node *temp = new Node(data);

        // (tail) |prev| data |next|    (temp) |prev| data |next|

        tail->next = temp;  // connect tail's next to temp 
        temp->prev = tail;  // connect temp's prev to tail
        tail = temp;        // update tail 
    }
};


void insertatposition(int data, int position, Node* &head, Node* &tail){
    // creating a pointer 
    Node* ptr = head;
    int count = 1;
    
    if(position == 0){
        insertathead(data, head, tail);
        return;
    }
    
    while(count <= position-1){
        ptr = ptr->next;
        count++;
    }
    
    Node* newnode = new Node(data);
    newnode->next = ptr;
    ptr->prev->next = newnode;
    newnode->prev = ptr->prev;
    ptr->prev = newnode;
    
};

void deletenode(int position, Node* &head){
    if(position == 1){
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }else{
        Node* current = head;
        Node* prev = head;

        int count = 1;
        while(count < position-1){
            prev = prev->next;
            current = current->next;
            count++;
        }
        current = current->next;
        // cout << prev->data << " " << current->data <<  endl;

        // Order matters
        prev->next = current->next;
        current->prev = NULL;
        current->next->prev = prev;
        current->next = NULL;

        delete current;
    }
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
    
    insertattail(80, tail, head);   
    print(head);    
    insertattail(90, tail, head);   
    print(head);    
    insertattail(100, tail, head);  
    print(head);    
    
    insertatposition(0, 7, head, tail);
    print(head);
    
    // printtail(tail);
    
    deletenode(1, head);
    print(head);

}