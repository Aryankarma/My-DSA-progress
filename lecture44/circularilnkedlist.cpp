#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){

        cout << "deconstructor is running " << endl;

        int value = this->data;
        while(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory clear for data : " << value << endl;
    }
};

void insertnode(Node* &tail, int availablenode, int nodedata){
    // asuming availablenode is present as data in some node (we have to set nodedata after it)
    
    // case 1: link list is empty (no nodes inserted)
    if(tail == NULL){
        Node* newnode = new Node(nodedata);
        tail = newnode;
        newnode -> next = newnode;
    }else{
        
        // case 2: link list is not empty and the availablenmde is present in the node somewhere
        Node* current = tail;
            
        while(current->data != availablenode){
            current = current->next;
        }
        // element is found and current is pointing to the node that contains availablenode as it's data  
        Node* newnode = new Node(nodedata);
        newnode->next = current->next;
        current->next = newnode;
    }
};


void print(Node* &tail){
    if(tail == NULL){
        cout << "CLL is empty, try inserting node." << endl;
        return;
    };

    Node* ptr = tail;

    // approach 1
    tail = tail->next;
    while(tail != ptr){
        cout << tail->data << " ";
        tail = tail->next;
    }

    // approach 2
    // do{  
    //     cout << tail->data << " ";
    //     tail = tail->next;
    // }while(tail != ptr);

    cout << endl;
}

void deletenode(Node* &tail, int nodedata){
    if(tail == NULL){
        cout << "CLL is empty, try inserting node." << endl;
        return;
    }else{
        Node* current = tail;
        Node* prev = current;

        while(current->data != nodedata){
            prev = current;
            current = current->next;
        }

        // removing connections of current node
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

int main(){
    
    Node* node1 = new Node(0);
    // no need of head
    Node* tail = NULL;
    
    // as we don't know the starting and ending nodes of a circular linked list we'll insert 
    // new nodes after the node whose data matches the given data...
    
    // print(tail);

    insertnode(tail, 1, 1);
    insertnode(tail, 1, 10);
    insertnode(tail, 10, 100);
    insertnode(tail, 100, 1000);

    print(tail);

    deletenode(tail, 100);
    deletenode(tail, 1000);
    deletenode(tail, 10);
    
    print(tail);
}