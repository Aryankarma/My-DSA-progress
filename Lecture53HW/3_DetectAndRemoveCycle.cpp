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

Node* checkLoopOptimized(Node* &head){
    
	if(head == NULL)
    return NULL;

	// Node* curr = head;
    Node* slow = head;
    Node* fast = head;

    while((slow != NULL) || (fast != NULL)){

        if(fast == NULL){
            return NULL;
        }   

        slow = slow->next;
        fast = fast->next;

        if(fast == NULL){
            return NULL;
        }else if(fast->next != NULL){
            fast = fast->next;
        }else{
            return NULL;
        }

        // loop found
        if(slow == fast){
            // cout << slow->data << endl;
            return slow;
        }

    }
    return NULL;
}


Node* loopStart(Node* &head){
     Node* loopFoundAt = checkLoopOptimized(head);

    if(loopFoundAt == NULL)
        return NULL;
    // if(loopFoundAt == head)
    //     return head;

	Node* slow = head;
    while(slow != loopFoundAt){
        // cout << "slow: " << slow->data << " " << loopFoundAt->data << endl;
        slow = slow->next;
        loopFoundAt = loopFoundAt->next;
    }
    return slow;
}

bool removeLoop(Node* &head){
    Node* startOfLoop = loopStart(head);

    // if(startOfLoop == head || startOfLoop == NULL)
    if(startOfLoop == NULL)
        return false;

    Node* temp = startOfLoop->next;
    while(startOfLoop != temp->next){
        temp = temp->next;
    }
    temp->next = NULL;

	return true;
}

int main(){
          
    Node* node1 = new Node(10);
          
    Node *head = node1;
    Node *tail = node1;


    insertattail(tail, 20);
    insertattail(tail, 30);
    insertattail(tail, 40);

    tail->next = head->next;

    Node* temp = checkLoopOptimized(head);

    if(checkLoopOptimized(head)){
        cout << "found loop with approach 2 " << endl;
        removeLoop(head);
        print(head);
    }else{
        cout << "couldn't find loop with approach 2 " << endl;
    };

    print(head);

}