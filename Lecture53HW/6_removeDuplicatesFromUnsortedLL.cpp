#include<bits/stdc++.h>
using namespace std;

/*  Problem Statement -  Remove Duplicates From an Unsorted Linked List

    You are given a linked list of N nodes. Your task is to remove the duplicate nodes from the linked list 
    such that every element in the linked list occurs only once i.e. in case an element occurs more than once, 
    only keep its first occurrence in the list.

    For example :
    Assuming the linked list is 3 -> 2 -> 3 -> 4 -> 2 -> 3 -> NULL.

    Number ‘2’ and ‘3’ occurs more than once. Hence we remove the duplicates and keep only their first 
    occurrence. So, our list becomes : 3 -> 2 -> 4 -> NULL.


    // We'll use set in our approach 

    What are sets?

    set: This is a container that stores a sorted set of unique elements. It is implemented using a 
    balanced binary search tree. Operations like insertion, deletion, and search have a time complexity of 
    O(log n), where n is the number of elements in the set.

    multiset: Similar to set, but it allows duplicate elements. Elements are stored in sorted order, 
    and insertion, deletion, and search operations also have a time complexity of O(log n).

    unordered_set: This is an unordered set implemented using a hash table. It stores a set of unique 
    elements, but unlike set, the elements are not stored in any particular order. Insertion, deletion, 
    and search operations have an average time complexity of O(1), making it faster for many operations compared 
    to set.

    unordered_multiset: Similar to unordered_set, but it allows duplicate elements.

*/

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

Node* removeDuplicates(Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    // Node* curr = head;

    // implementing set
    unordered_set<int> check;

    // check.insert(1);
    // check.insert(10);
    // check.insert(10);
    // check.insert(10);
    // check.insert(100);

    // while(curr != NULL){

    //     if(check.find(curr->data)   ){

    //     }

    //     curr = curr->next;
    // }

};

int main(){
          
    Node* node1 = new Node(4);
          
    Node *head = node1;
    Node *tail = node1;

    insertattail(tail, 2);
    insertattail(tail, 5);
    insertattail(tail, 4);
    insertattail(tail, 2);
    insertattail(tail, 2);

    print(head);

    removeDuplicates(head);

    print(head);

}