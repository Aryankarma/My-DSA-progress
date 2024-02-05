// SINGLY LINKED LIST
#include<bits/stdc++.h>
#include<map>
using namespace std;


/*  Clone a linked list with next and random pointer

    Problem Statement -

    You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. 
    You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  
    i.e. a->arb = b (arb is pointer to random node).

    Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node has its 
    value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should 
    point to new nodes in the copied list such that the pointers in the original list and copied list represent the 
    same list state. None of the pointers in the new list should point to nodes in the original list.

    For example, if there are two nodes X and Y in the original list, where X.arb --> Y, then for the corresponding two 
    nodes x and y in the copied list, x.arb --> y.

    Return the head of the copied linked list.

*/

// Link to GFG [https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1]

class Node{
    public:
    int data;   // integer data
    Node *next;  // pointer variable "add" that stores the address of object
    Node *ran;  // pointer variable "add" that stores the address of object

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->ran = NULL;
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

void printRan(Node* &head){
    Node* current = head;

    while(current != NULL){
        if(current->ran){
            cout << "curr data: " << current->data << " curr random: " << current->ran->data << endl;
        } 
        current = current->next;
    }
    cout << endl;
}

int main(){       
          
    Node* OriginalList = new Node(1);        
          
    Node *headOrig = OriginalList;
    Node *tailOrig = OriginalList;

    insertattail(tailOrig, 2);
    insertattail(tailOrig, 3);
    insertattail(tailOrig, 4);

    headOrig->ran = headOrig->next; // (1,2)    
    headOrig->next->ran = tailOrig; // (2,4)

    print(headOrig);
    cout << "printing random pointers..." << endl;
    printRan(headOrig);

    Node* CloneList = new Node(headOrig->data);
    Node* headClone = CloneList;
    Node* tailClone = CloneList;

    Node* currOrig = headOrig;
    Node* currClone = headClone;
    
    // copying original list with next pointer
    while(currOrig->next != NULL){
        insertattail(tailClone, currOrig->next->data);
        currOrig = currOrig->next;
    }

    cout << "original list: " << endl;
    print(headOrig);
    cout << "clone list: " << endl;
    print(headClone);

    // mapping original list nodes with clone list nodes
    currOrig = headOrig;
    currClone = headClone;

    map<Node*, Node*> mapping;
    while(currOrig != NULL){
        mapping[currOrig] = currClone;
        currOrig = currOrig->next;
        currClone = currClone->next;
    }

    // setting up random pointers in the clone list
    currOrig = headOrig;
    currClone = headClone;

    while(currClone != NULL){
        if(currOrig->ran){
            // cout << "currOrig->ran->data " << mapping[currOrig->ran]->data << endl;
            currClone->ran = mapping[currOrig->ran];
        }
        currOrig = currOrig->next;
        currClone = currClone->next;
    }

    // reseting for print test (temporary)
    currOrig = headOrig;
    currClone = headClone;

    cout << "printing random poniters: " << endl;

    cout << "original list randoms: " << endl;
    printRan(headOrig);
    cout << "clone list randoms: " << endl;
    printRan(headClone);
}




// GFG worked solution {approach 1, time O(n), space O(n)} -


// class Solution
// {
//     public:
    
//     void insertattail(Node* &tail, int data){
//         Node *temp = new Node(data);    
//         tail -> next = temp;
//         tail = temp;
//     }

//     Node *copyList(Node *head){
        
//         Node *headOrig = head;
//         Node *tailOrig = head;
    
//         Node* CloneList = new Node(headOrig->data);
//         Node* headClone = CloneList;
//         Node* tailClone = CloneList;
    
//         Node* currOrig = headOrig;
//         Node* currClone = headClone;
        
//         // copying original list with next pointer
//         while(currOrig->next != NULL){
//             insertattail(tailClone, currOrig->next->data);
//             currOrig = currOrig->next;
//         }
        
//         // mapping original list nodes with clone list nodes
//         currOrig = headOrig;
//         currClone = headClone;
    
//         map<Node*, Node*> mapping;
//         while(currOrig != NULL){
//             mapping[currOrig] = currClone;
//             currOrig = currOrig->next;
//             currClone = currClone->next;
//         }
    
//         // setting up random pointers in the clone list
//         currOrig = headOrig;
//         currClone = headClone;
        
//         while(currClone != NULL){
//             if(currOrig->arb){
//                 // cout << "currOrig->arb->data " << mapping[currOrig->arb]->data << endl;
//                 currClone->arb = mapping[currOrig->arb];
//             }
//             currOrig = currOrig->next;
//             currClone = currClone->next;
//         }
    
//         return headClone;
//     }

// };