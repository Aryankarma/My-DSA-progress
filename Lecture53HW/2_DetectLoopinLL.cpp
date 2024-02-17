#include<bits/stdc++.h>
using namespace std;

/*  Problem statement
    Kevin has given you a Singly Linked List that contains only integers. You have to determine if it forms a 
    cycle or not.

    A cycle occurs when a node's next pointer points back to a previous node in the list.

    

*/

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

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

// taking O(n) space and time
bool checkLoop(Node* &head){
    Node* curr = head;
    map<Node*, bool> mapping;

    while(curr != NULL){
        mapping[curr] = true;
        if(curr->next != NULL){
            if(mapping[curr->next] == true){
                return true;
            }
        }
        curr = curr->next;
    }
    return false;
};

// approach with O(1) space and O(n) time complexity
bool checkLoopOptimized(Node* &head){
    // Node* curr = head;
    Node* slow = head;
    Node* fast = head->next;

    while((slow != NULL) || (fast != NULL)){

        if(fast == NULL){
            return false;
        }

        // loop found
        if(slow == fast){
            return true;
        }

        slow = slow->next;
        fast = fast->next;

        if(fast == NULL){
            return false;
        }else if(fast->next != NULL){
            fast = fast->next;
        }else{
            return false;
        }
    }
    return false;
}

int main(){
          
    Node* node1 = new Node(10);        
          
    Node *head = node1;
    Node *tail = node1;

    insertattail(tail, 20);
    insertattail(tail, 30);
    insertattail(tail, 40);

    // tail->next = head->next->next;

    if(checkLoop(head)){
        cout << "found loop with approach 1 " << endl;
    }else{
        cout << "couldn't find loop with approach 1 " << endl;
    };
    
    if(checkLoopOptimized(head)){
        cout << "found loop with approach 2 " << endl;
    }else{
        cout << "couldn't find loop with approach 2 " << endl;
    };
}