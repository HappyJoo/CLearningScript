/* DESCRIPTION
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.
Example:
    Input: 1->2->3->4->5->NULL, m = 2, n = 4
    Output: 1->4->3->2->5->NULL
*/

/* HOW TO SOLVE IT
It's really easy to understand, but tricky to write.
So in the list, you start from the first node.
1,Move to m. 
2,reverse from m to n. 
3,bring the pieces together, done.

It's not difficult to undertand. You just cut out the middle part.
Reverse it. Then connect three part back together.
*/


// CODE PART
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//iterative way
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(head == NULL) return head; // border condition
    struct ListNode *cur = head, *pre = NULL;

    // move pointer to node m.
    while(m>1) // or m-1>0, the time of the loop is m-1.
    {
        pre = cur;
        cur = cur->next;
        m--;
        n--; // for the next while loop to be n-m times.
    }

    struct ListNode *tem, *pointerbeforestart, *tail;
    pointerbeforestart = pre; // pointer brfore the start of the reverse part. need to point this to the reversed part
    tail = cur; // pointer at the start of the reverse part. need to point this to the last part

    // reverse list from m to n.
    while(n>0)
    {
        tem = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tem;
        n--;
    }

    // deal with when 'm=1'
    if (pointerbeforestart != NULL){
        pointerbeforestart->next = pre;
    } else head = pre;
    
    // connect reversed list to the last part
    tail->next = cur;

    // return the first node of this list. we never change head.
    return head;
}