#include<bits/stdc++.h>
#include<map>
#include<set>
using namespace std;

/*  Problem Statement -  Remove Duplicates From an Unsorted Linked List 

    You are given a linked list of N nodes. Your task is to remove the duplicate nodes from the linked 
    list such that every element in the linked list occurs only once i.e. in case an element occurs more 
    than once, only keep its first occurrence in the list.

    for example: Assuming the linked list is 3 -> 2 -> 3 -> 4 -> 2 -> 3 -> NULL.

    Number ‘2’ and ‘3’ occurs more than once. Hence we remove the duplicates and keep only their first occurrence. 
    So, our list becomes : 3 -> 2 -> 4 -> NULL.

    Link to codespace [https://www.codingninjas.com/studio/problems/remove-duplicates-from-unsorted-linked-list_1069331?source=youtube&campaign=YouTube_Lovebabbar29thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar29thJan]    

*/


class Node{
    public:
    int data;
    Node *next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


void insertattail(int data, Node* &tail){
        Node *temp = new Node(data);
    
        tail->next = temp;  // connect tail's next to temp
        tail = temp;        // update tail 
};


void print(Node* &head){
    Node* temp  = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
};

bool elementExists(int checkValue, map<int, int> map){
    for(int i=0; i<map.size(); i++){
        if(checkValue == map[i]){
            return true;
        }
    }
    return false;
}

void removeDuplicated(Node *head) {
/*
    approach 1 (5/10)
    1. create a map.
    2. iterate through the linked list
    3. check if nth value in the linked list is already present on the map
    4. if not(store the nth values with their keys in a map)
    5. if already present in the map(delete the node)

    approach 2 (7/10)
    1. store all unique values of linked list in the map
    2. take the nth value from the map
    3. remove every second node that contains the same value
*/

    map<int, int> map;
    Node* temp = head;


    // 1. store all unique values of linked list in the map
    while(temp->next != NULL){
        if(!elementExists(temp->data, map)){
            map[map.size()] = temp->data;
        }
        temp = temp->next;
    }

    // for(int i=0; i<map.size(); i++){
    //     cout << map[i] << " ";
    // }    

    // cout << endl;

    // 2. take the nth value from the map
    int maplength = map.size();
    int templength = 1;

    temp = head;

    while(templength < maplength){
        int currentnode = map[templength];

        // 3. remove every second node that contains the same value
        int count = 0;

        while(temp->next != NULL){
            if(temp->data == currentnode){
                count++;
            }
            if(temp->next->data == currentnode){
                count++;
                if(count >= 2){
                    Node* deletenode = temp->next;
                    temp->next = temp->next->next;
                    delete(deletenode);
                }else{
                    temp = temp->next;
                }       
            }else{
                temp = temp->next;
            }
        }
        templength++;
    }
}

// working but needs optimization (TLE)
void removeDuplicate2(Node* head){
    Node* check = head;
    while(check != NULL){
        Node* temp = check;
        cout << "running 1" << endl;
        
        while(temp->next != NULL){
            cout << "running 2" << endl;
            if(temp->next->data == check->data){
                Node* deletenode = temp->next;
                temp->next = temp->next->next;
                delete(deletenode);

                cout << "running 3" << endl;
            }else{
                cout << "increasing temp" << endl;
                temp = temp->next;
            }
        }
        check = check->next;
    }
    return;
}


// approach 2 - sort the linked list and then apply the function to remove duplicates from sorted list
// approach 3 - create a map iterate through it once, in the second iteration delete every node that is present in the map

void removeDuplicate3(Node* head){
    Node* temp = head;
    map<int, bool> nodedata;

    while(temp->next != NULL){
        int data = temp->data;
        nodedata[data] = true;

        if(nodedata[temp->next->data]){
            Node* removeNode = temp->next;
            temp->next = temp->next->next;
            delete(removeNode);
            cout << "removed a node" << endl;
        }else{
            temp = temp->next;
        }
    }

    return;
}

void removeDuplicate4(Node* head){
    // sort the linked list
    
    // delete duplicates from sorted list
    
    
    return;
}

// optimized map function
Node* removeDuplicate5(Node* head){
    if (head == nullptr) {
        return nullptr;
    }

    unordered_set<int> seen;
    Node* current = head;
    Node* previous = nullptr;

    while (current){
        if(seen.find(current->data) != seen.end()) {
            previous->next = current->next;
        }else{
            seen.insert(current->data);
            previous = current;
        }
        current = previous->next;
    }
    return head;
}

int main(){
    Node *node1 = new Node(120);
    Node *head = node1;
    Node *tail = node1;

    insertattail(2, tail);
    insertattail(5, tail);
    insertattail(4, tail);
    insertattail(2, tail);
    insertattail(2, tail);

    // removeDuplicated(head);
    
    // removeDuplicate2(head); // O(n^2) time complexity
    // print(head);

    // removeDuplicate3(head); // optimized but still TLE :(   O(n)
    // print(head);

    // removeDuplicate4(head);
    // print(head);

    removeDuplicate5(head);
    print(head);
}