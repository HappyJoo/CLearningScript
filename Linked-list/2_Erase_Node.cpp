struct Node *erase(struct Node *head, int ind) {
    struct Node *ret, *p = &ret;
    ret.next = head;
    while (ind--) p = p->next;
    p->next = p->next->next;
    return ret.next;
}
// To help you understand haha~
// Imaging that, cut one line and reconnect another line.
--p----p.next----p.next.next--|   ---->   |----p     p.next----
                              |   ---->   |    \ 
                              |   ---->   |     \ 
                              |   ---->   |      p.next.next----
