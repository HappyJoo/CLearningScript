/*
    Reverse a singly linked list.
    Input: 1->2->3->4->5->NULL
    Output: 5->4->3->2->1->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 *
 */

// Iterative way.
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p=NULL, *tem;
    while(head)
    {
        tem = head->next;
        head->next = p;
        p = head;
        head = tem;
    }
    return p;
}

// Recursive way.
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head; // Border condition.
    struct ListNode *p=head->next; // p is the pointer of the next of head
    head->next = NULL; // then turn head back
    struct ListNode *new = reverseList(p); // recurse
    p->next = head; // turn p back
    return new; // return new
}