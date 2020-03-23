/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * Example:
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
*?


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1) return l2; // if l1 == NULL
    if(!l2) return l1; // if l2 == NULL

    // since we r using l1 and l2, not need to create another two node.
    struct ListNode  *run, *head; // run for running through the new list
                                  // head node used for returning the list
    if(l1->val <= l2->val) // give run the first node
        {
            run = l1;
            l1 = l1->next; 
        } else {
            run = l2;
            l2 = l2->next;
        }
    head = run; // set head as the first node of the new list.
    
    while (l1 && l2) {
        if(l1->val <= l2->val)
        {
            run->next = l1;
            l1 = l1->next; // move l1
        } else{
            run->next = l2;
            l2 = l2->next; // move l2
        }
        run = run->next; // move run
    }

    // if(l1!=NULL) run->next = l1; if(l2!=NULL) run->next = l2;
    if(l1) {
        run->next = l1;
    } else run->next = l2;
    
    return head; // head node of the new list.
}