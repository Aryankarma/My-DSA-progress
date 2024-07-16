// pretty simple problem;

/*  Problem Statement -  k-th node from the end of the linked list
    Given the head node of the singly linked list and an integer ‘k’, , find the value at the kth node from
    the end of the linked list.

    For example:
    51 -> 37 -> 77 -> 12 -> 78

    For the above-linked list, if k=2, then the value at the kth i.e second node from the end is ‘12’.

    Link to CodingNinjas [https://www.naukri.com/code360/problems/k-th-node-from-the-end-of-the-linked-list_1171164?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM]

*/

node *findKthFromLast(node *head, int k){
    int lengthofLL = 0;
    node *curr = head;
    while (curr != NULL){
        curr = curr->next;
        lengthofLL++;
    }

    curr = head;

    for (int i = 0; i < (lengthofLL - k); i++){
        curr = curr->next;
    }

    return curr;
}