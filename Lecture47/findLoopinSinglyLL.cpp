#include<bits/stdc++.h>
#include<map>
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

bool detectLoop(Node* &head){
    if(head == NULL){
        return false;
    }

    // generate map
    map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL){
        // cycle is present
        if(visited[temp] == true){
            cout << "A cycle is present in this loop. " << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;       
    }
    return false;
}

Node* floyedLoopDetection(Node* &head){
    Node* slow = head;
    Node* fast = head;
    
    if(head == NULL){
        return NULL;
    }

    while(slow != NULL && fast != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }

        if(slow == fast){
            return slow; 
        }
    }

    return NULL;
};

Node* loopStart(Node* &head){
    Node* loopFoundAt = floyedLoopDetection(head);
    Node* slow = head;

    while(slow != loopFoundAt){
        slow = slow->next;
        loopFoundAt = loopFoundAt->next;
    }
    return slow;
}

void removeLoop(Node* &head){
    Node* startOfLoop = loopStart(head);
    Node* temp = startOfLoop->next;

    while(startOfLoop != temp->next){
        temp = temp->next;
    }

    temp->next = NULL;
}

int main(){       
          
    // creating in heap memory
    Node* node1 = new Node(10);
          
    // cout << "Address " << node1->next << endl;
    // cout << "Data : " << node1->data << endl;

    Node *head = node1;
    Node *tail = node1;

    insertattail(tail, 20);
    insertattail(tail, 30);
    insertattail(tail, 40);
    insertattail(tail, 50);

    print(head);

    // creating a loop
    tail->next = head->next;

    if(detectLoop(head)){
        cout << "Loop is present in the LL " << endl;
    } 
    cout << "loop found at: " << floyedLoopDetection(head)->data << endl;    
    cout << "Starting point of loop: " << loopStart(head)->data << endl;
    // before removing loop
    // print(head);
    // removing loop 
    removeLoop(head);
    // after removing loop
    print(head);

}