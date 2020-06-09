ListNode* swapper(ListNode* head) {
    if(head->next != NULL) {
        ListNode* swapper = head;
        head = head->next;
        swapper->next = head->next;
        head->next = swapper;
    }
    return head;
}

ListNode* swapPairs(ListNode* head) {
    ListNode* newHead = new ListNode(0, head);
    ListNode* cur = newHead;
    while(cur->next != NULL) {
        cur->next = swapper(cur->next);
        if(cur->next->next == NULL) break;
        cur = cur->next->next;   
    }
    return newHead->next;
}
