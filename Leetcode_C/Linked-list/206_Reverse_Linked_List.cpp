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