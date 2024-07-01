/* Problem statement -  Flatten A Linked List

    You are given a linked list containing 'n' 'head' nodes, where every node in the linked list contains two pointers:

    (1) ‘next’ which points to the next node in the list
    (2) ‘child’ pointer to a linked list where the current node is the head.

    Each of these child linked lists is in sorted order and connected by 'child' pointer.
    Your task is to flatten this linked such that all nodes appear in a single layer or level in a 'sorted order'.

    Explanation:
    The returned linked list should be in a sorted order. All the elements in this returned linked list are connected
    by 'child' pointers and 'next' pointers point to null.

*/

// link to codingNinjas [https://www.naukri.com/code360/problems/flatten-a-linked-list_1112655?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM]

Node *merge2LinkedList(Node *head1, Node *head2){
    Node *temp = new Node(-1);
    Node *curr = temp;
    head1->next = NULL;

    while (head1 != NULL && head2 != NULL){
        if (head1->data <= head2->data){
            curr->child = head1;
            curr = head1;
            head1 = head1->child;
        }else{
            curr->child = head2;
            curr = head2;
            head2 = head2->child;
        }
    }

    if (head1 != NULL){
        curr->child = head1;
    }else{
        curr->child = head2;
    }

    Node *finalHead = temp->child;
    delete temp;
    return finalHead;  
}

Node *flattenLinkedList(Node *head){
    if (head == NULL || head->next == NULL)
        return head;

    Node *mergedHead = flattenLinkedList(head->next);
    return merge2LinkedList(head, mergedHead);
}