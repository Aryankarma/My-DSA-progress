#include<bits/stdc++.h>
using namespace std;

// Check if Linked List is Palindrome
/*
    Problem Statement: Given a singly linked list of size N of integers. The task is to check if the given 
    linked list is palindrome or not.

    Example 1:

    Input:
    N = 3
    value[] = {1,2,1}
    Output: 1
    Explanation: The given linked list is
    1 2 1 , which is a palindrome and
    Hence, the output is 1.
    Example 2:

    Input:
    N = 4
    value[] = {1,2,3,4}
    Output: 0
    Explanation: The given linked list
    is 1 2 3 4 , which is not a palindrome
    and Hence, the output is 0.
    Your Task:
    The task is to complete the function isPalindrome() which takes head as reference as the only 
    parameter and returns true or false if linked list is palindrome or not respectively.

    Expected Time Complexity: O(N)
    Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)
*/

// Link to GFG [https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1]


// VS code solution 
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


void insertathead(Node* &head, int data){
    // creating new node
    Node *temp = new Node(data);
    temp -> next = head;
    head = temp;
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

Node* findMiddle(Node* temphead){
    Node* slow = temphead;
    Node* fast = temphead;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next;

        if(fast->next != NULL){
            fast = fast->next;
            cout << "printing function : ";
            print(fast);
        }
    }

    return slow;
}

Node* reverseHalf(Node* temphead){
    Node* prev = NULL;
    Node* curr = temphead;
    Node* nextptr = curr->next;

    while(curr != NULL){
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    return prev;  
}

bool checkEqual(Node* leftHalf, Node* rightHalf){
    while((leftHalf != NULL) && (rightHalf != NULL)){
        if(leftHalf->data == rightHalf->data){
            leftHalf = leftHalf->next;
            rightHalf = rightHalf->next;
        }else{
            return false;
        }
    }

    return true;
}

bool checkPalindrome(Node* head){
    Node* middle;
    Node* reverseNode;
    bool palindromeStatus;

    middle = findMiddle(head);
    reverseNode = reverseHalf(middle->next);
 
    // cout << "printig half original LL: ";
    // print(head);

    // cout << "printig half reversed LL: ";
    // print(reverseNode);
    
    palindromeStatus = checkEqual(head, reverseNode);

    cout << "this is middle data: " << middle->data << endl;
    return palindromeStatus;
}

int main(){

    Node* node1 = new Node(1);
    Node *tail = node1;
    Node *head = node1;

    insertattail(tail, 2);
    insertattail(tail, 3);
    insertattail(tail, 3);
    insertattail(tail, 2);
    insertattail(tail, 1);
    insertattail(tail, 9);

    // print(head);

    if(checkPalindrome(head)){
        cout << endl;
        cout << endl;
        cout << "LL is palindrome" << endl;
    }else{
        cout << endl;
        cout << endl;
        cout << "LL is not palindrome" << endl;
    };

}





// GFG solution

class Solution{
  public:
    
    bool checkEqual(Node* leftHalf, Node* rightHalf){
        while((leftHalf != NULL) && (rightHalf != NULL)){
            if(leftHalf->data == rightHalf->data){
                leftHalf = leftHalf->next;
                rightHalf = rightHalf->next;
            }else{
                return false;
            }
        }
        return true;
    }
        
    Node* reverseHalf(Node* temphead){
        Node* prev = NULL;
        Node* curr = temphead;
        Node* nextptr = curr->next;
    
        while(curr != NULL){
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        return prev;  
    }
    
        
    Node* findMiddle(Node* temphead){
        Node* slow = temphead;
        Node* fast = temphead;
    
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next;
    
            if(fast->next != NULL){
                fast = fast->next;
            }
        }
        return slow;
    }
    
    bool checkPalindrome(Node* head){
        Node* middle;
        Node* reverseNode;
        bool palindromeStatus;
    
        middle = findMiddle(head);
        reverseNode = reverseHalf(middle->next);
        
        palindromeStatus = checkEqual(head, reverseNode);
    
        return palindromeStatus;
    }
  
    bool isPalindrome(Node *head){
        
        if(head->next == NULL){
            return true;
        }
        
        return checkPalindrome(head);
    }
};