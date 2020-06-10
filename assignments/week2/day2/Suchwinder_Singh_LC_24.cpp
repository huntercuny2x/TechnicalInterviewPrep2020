// Swap Nodes in Pairs

ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next==nullptr) return head;
    ListNode *before = head;
    ListNode *current = head->next;
    ListNode **previous = &head; // pointer to the pointer to the head
    while (current != nullptr) {
        before->next=current->next; // prev pointer to current pointers next
        current->next=before; // current to prev
        // finished swap but need the previous pointer to point to correct place
        *previous = current; // pointer dereferenced to pointer and assigning that to current
        previous = &(before->next); // get pointer to next value e.g. Node with val 1 is pointer to 3 in 2nd iteration of example test case
        before = before->next;
        if(before == nullptr) break;
        current = before->next;            
    }
    return head;
}
