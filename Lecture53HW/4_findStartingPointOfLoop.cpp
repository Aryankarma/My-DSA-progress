// SINGLY LINKED LIST

#include<bits/stdc++.h>
using namespace std;

/*  Problem statement - Linked List Cycle II
    
    You are given a singly linked list that may or may not contain a cycle. You are supposed to return the 
    node where the cycle begins, if a cycle exists, else return 'NULL'.
    
    A cycle occurs when a node's next pointer returns to a previous node in the list.
*/

// Link to CodingNinjas [https://www.codingninjas.com/studio/problems/detect-the-first-node-of-the-loop_1112628?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker]

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

	Node* slow = head;
    while(slow != loopFoundAt){
        cout << "slow: " << slow->data << " " << loopFoundAt->data << endl;
        slow = slow->next;
        loopFoundAt = loopFoundAt->next;
    }
    return slow;
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

    Node* temp2 = loopStart(head);   
    cout << "loop starts at: " << temp2->data << endl;
}