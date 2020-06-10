struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/* At the very start we create two new pointers to help iterating through
 * we then can just set head to head->next because that will always be the new head
 * then we start going through the linkedlist and have one pointer ahead of current
 * and then setting current to point to the next node of tmp and then linking tmp
 * back to current. This will do the swapping of a pair and then we just need to move
 * current and tmp ahead of the linked list to later swap another pair
 */ 
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* current = head, *tmp;
    head = head->next;

    while (current != nullptr && current->next != nullptr) {
        tmp = current;
        current = current->next;
        tmp->next = current->next;
        current->next = tmp;
        current = tmp->next;
        if (current != nullptr && current->next != nullptr) 
            tmp->next = current->next;
    }

    return head;
}