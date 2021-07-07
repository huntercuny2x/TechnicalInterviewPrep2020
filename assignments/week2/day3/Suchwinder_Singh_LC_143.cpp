// first get the mid Node of the list

// then reverse the second half list

// finally merge the two half lists

// I had to look at outside sources for guidance and dont fully understand how it works

void reorderList(ListNode *head) {
    if (!head) return;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *p1 = &dummy, *p2 = &dummy;
    for (; p2 && p2->next; p1 = p1->next, p2 = p2->next->next);
    for ( ListNode *prev = p1, *curr = p1->next; curr && curr->next; ){
        ListNode *tmp = curr->next;
        curr->next = curr->next->next;
        tmp->next = prev->next;
        prev->next = tmp;
    }
    for ( p2 = p1->next, p1->next = NULL,p1 = head; p2; ){
        ListNode *tmp = p1->next;
        p1->next = p2;
        p2 = p2->next;
        p1->next->next = tmp;
        p1 = tmp;
    }
}