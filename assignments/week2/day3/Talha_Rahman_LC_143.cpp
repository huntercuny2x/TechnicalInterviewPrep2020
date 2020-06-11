struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// simple reverse function
ListNode* reverse(ListNode* head) {
    ListNode* previous = nullptr;
    ListNode* current = head, *next;
    
    while(current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

// alternates merging between a node of l1 and node of l2
void merge(ListNode* l1, ListNode* l2) {
    while(l1 != nullptr) {
        ListNode* l1_next = l1->next;
        ListNode* l2_next = l2->next;
        
        l1->next = l2;
        
        if (l1_next == nullptr) break;
        
        l2->next = l1_next;
        l1 = l1_next;
        l2 = l2_next;
    }
}

/**
 *  My logic is something like this
 *  starting list:
 *  1 -> 2 -> 3 -> 4
 *  Break list into two parts
 *  1 -> 2
 *  3 -> 4
 *  Reverse 2nd half of list
 *  1 -> 2 -> null
 *  4 -> 3 -> null
 *  Start connecting them back in the right order
 *  1 -> 4 -> 2 -> 3 -> null
 * 
 */
void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    
    // By the end of this while loop, we have a head pointer
    // and tail pointer for both lists. 
    ListNode* l1_head = head, *l1_tail;
    ListNode* l2_head = head, *l2_tail = head;
    while(l2_tail != nullptr && l2_tail->next != nullptr) {
        l1_tail = l2_head;
        l2_head = l2_head->next;
        l2_tail = l2_tail->next->next;
    }
    
    l1_tail->next = nullptr;
    
    l2_head = reverse(l2_head);
    
    merge(l1_head, l2_head);
}