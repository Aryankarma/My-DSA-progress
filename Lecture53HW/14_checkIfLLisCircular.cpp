
/* Problem Statement - 

    You are given a Singly Linked List of integers. You have to find if the given linked list is circular or not.
    A circular linked list is a sequence of elements in which every element has a link to its next element 
    in the sequence and the last element has a link to the first element. This means that circular linked list is similar to the single linked list except that the last node points to the first node in the list.    
*/

// Link to codingNinjas [https://www.naukri.com/code360/problems/is-it-a-circular-linked-list_981265?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM]

#include <bits/stdc++.h> 
bool circularLL(Node* head){
    Node* temp = head;

    while( temp != NULL ){
        temp = temp->next;
        if(temp == head){
            return true;
        }
        if(temp == NULL){
            return false;
        }
    }
}