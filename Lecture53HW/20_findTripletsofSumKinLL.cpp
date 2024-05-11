#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*  Problem Statement -   Count Triplets

    You have been given an integer ‘X’ and a non-decreasing sorted doubly linked list with distinct nodes.

    Your task is to return the number of triplets in the list that sum up to the value ‘X’.
*/

// Link to codingNinjas [https://www.naukri.com/code360/problems/count-triplets_873377?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM]

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int value){
        this->data = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
    ~Node(){
        int value = this->data;
        if(next != nullptr){
            delete next;
            next = NULL;
        }
        cout << "Node with value : " << value << " got deleted. " << endl;
    }
};

int getLength(Node* &head){
    
    Node* temp = head;
    int count = 0;

    while(temp != nullptr){
        count++;
    }

    return count;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void printtail(Node* &tail){
    Node* temp = tail;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

void insertathead(int data, Node* &head, Node* tail){
    Node* temp = new Node(data);

    // if the list is empty
    if(head == nullptr){
        head = temp;
        tail = temp;
    }else{
    // the list is not empty

        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertattail(int data, Node* head, Node* &tail){
    Node* temp = new Node(data);

    // if the list is empty
    if(tail == nullptr){

        head = temp;
        tail = temp;
    }else {
    // the list is not empty

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// approach 1, mostly worked but codingninjas has an invalid input that failed this algo to work on their platform
void findTripletsInDLL(Node* head, int k){
    cout << "entered the function" << endl;
    Node* first = head;
    Node* second = first->next;
    vector<pair<int, int>> pairs;
    // vector<tuple<int, int, int>> triplets;
    set<tuple<int, int, int>> triplets;

    while (first->data + second->data < k){
        // cout << "inside while" << endl;
        if ( first->data + second->data < k ){
            pairs.push_back({ first->data, second->data });
            if(second->next != NULL){
                if(first->data + second->next->data >= k){
                    first = first->next;
                    second = first->next;
                    // cout << "i am here " << endl;
                    // if( first->data + second->data >= k ){
                    //     cout << " this deserves to break " << endl;
                    //     break;
                    // }
                }else{
                    second = second->next;
                }
            }else{
                first = first->next;
                second = first->next;
            }
        }
    }

    cout << "size of pairs " << pairs.size() << endl;

    for(const auto &p: pairs){
        cout << p.first << " " << p.second << endl;
    }

    Node *tempptr = head;
    int pairSizePtr = 0;

    while (pairSizePtr < pairs.size()){
        // cout << "checking for " << pairs[pairSizePtr].first << " & " << pairs[pairSizePtr].second << endl;
        if ((tempptr->data != pairs[pairSizePtr].first) && (tempptr->data != pairs[pairSizePtr].second)){
            if (pairs[pairSizePtr].first + pairs[pairSizePtr].second + tempptr->data == k){
                // normal push
                // triplets.push_back({pairs[pairSizePtr].first, pairs[pairSizePtr].second, tempptr->data});
                
                // sorted integers push so that we can delete the same triplets
                int a = pairs[pairSizePtr].first;
                int b = pairs[pairSizePtr].second;
                int c = tempptr->data;
                triplets.insert({min({a, b, c}), a + b + c - max({a, b, c}) - min({a, b, c}), max({a, b, c})});

                // reset pointers
                tempptr = head;
                pairSizePtr = pairSizePtr + 1;
            }else{
                if(tempptr->next != NULL){
                    tempptr = tempptr->next;
                }else{
                    // reset pointers
                    tempptr = head;
                    pairSizePtr = pairSizePtr + 1;
                }
            }
        }else{
            if (tempptr->next != NULL){
                tempptr = tempptr->next;
            }else{
                // reset pointers
                tempptr = head;
                pairSizePtr = pairSizePtr + 1;
            }
        }
    }

    cout << "size of triplets " << triplets.size() << endl;

    for (const auto &t : triplets){
        cout << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << endl;
    }
}

int main(){
    Node* listhead = new Node(1);

    Node* head = listhead;
    Node* tail = listhead;

    insertattail(4, head, tail);
    insertattail(6, head, tail);
    insertattail(2, head, tail);

    int k = 0;

    cout << "Enter number to find pairs : " << endl;
    cin >> k;

    findTripletsInDLL(head, k);
} 