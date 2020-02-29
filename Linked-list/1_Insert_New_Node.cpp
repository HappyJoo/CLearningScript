struct Node *insert(struct Node *head, int ind, struct Node *a) {
    struct Node ret, *p = &ret;
    ret.next = head;
    while (ind--) p = p->next;
    a->next = p->next;
    p->next = a;
    return ret.next;
}

// To help you understand haha~
// Just imagine cut and reconnect lines.
// ----p----p.next----|    ---->   |----p     p.next----
//                    |   ---->   |     \   /
//                    |   ---->   |      \ /
// -------a-----------|   ---->   |       a