#include<bits/stdc++.h>
using namespace std;

// Middle of Linked List
/*  Problem Statement - Given a singly linked list of 'N' nodes. The objective is to determine the middle node of a singly linked list. 
    However, if the list has an even number of nodes, we return the second middle node.

    Link to codespace [https://www.codingninjas.com/studio/problems/middle-of-linked-list_973250?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan] 
*/

class Node{

    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

void insertathead(Node* &head, int data){

    Node* temp = new Node(data);

    temp->next = head; 
    head = temp;

}

void insertattail(Node* &tail, int data){

    Node* temp = new Node(data);

    tail->next = temp; 
    tail = temp;
}

void print(Node* head){
    Node* current = head;

    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
};

int getLength(Node* head){
    Node* temp = head;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
};

int getMiddle(int middle, Node* head){
    // cout << middle << endl;
    Node* current = head;

    while(middle > 0){
        current = current->next;
        middle--;
    }

    return current->data;
}

int getMiddle2(Node* head){
    // edge cases (NodeList having 0 or 1 node)

    if(head == NULL || head->next == NULL){
        return head->data;
    }

    Node* oneStep = head;
    Node* twoStep = head->next;

    while(twoStep != NULL){
        twoStep = twoStep->next;
        if(twoStep != NULL){
            twoStep = twoStep->next;
        }
        oneStep = oneStep->next;    
    }

    return oneStep->data;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    // insertathead(head, 2);
    // insertathead(head, 3);
    // insertathead(head, 4);
    // insertathead(head, 5);
    // insertathead(head, 6);
    
    
    insertattail(tail, 2);
    insertattail(tail, 3);
    insertattail(tail, 4);
    insertattail(tail, 5);
    insertattail(tail, 6);
    insertattail(tail, 7);

    // approach 1, time complexity = O(n) + O(n/2) [O(n) - for getMiddle function | O(n/2) - for getMiddle function]
    int middleElementAt;
    middleElementAt = getLength(head)/2;
    
    cout << endl << "Nodelist: ";
    print(head);

    cout << "Middle Element of Nodelist: " << getMiddle(middleElementAt, head) << endl;

    // approach 2, for a bit better complexity = O(n/2) [almost equals O(n)]
    cout << "Middle Element of Nodelist through approach 2: " << getMiddle2(head) << endl << endl;

}