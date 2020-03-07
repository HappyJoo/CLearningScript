#include <stdio.h>

int hasCycle(struct Node *head) {
    if (head == NULL) return 0;
    int sl = head, fa = head;
    do {
        sl = sl->next;
        fa = fa->next;
        if (fa == NULL) return 0;
        fa = fa->next;
    } while (sl != fa && fa);
    return fa == sl;
}