void reorderList(ListNode* head) {
  if(head == NULL) return;

  ListNode* firstElement = head;
  map<ListNode*, ListNode*> parent;
  ListNode* dad = NULL;
  while(head != NULL) {
      parent[head] = dad;
      dad = head;
      head = head->next;
  }

  ListNode* tail = dad;
  head = firstElement;

  while(true) {
      if(head == tail || head->next == tail) {
          tail->next = NULL;
          break;
      }

      //cout << "Head -> " << head->val << ", Tail -> " << tail->val << endl;

      ListNode* afterNext = head->next;
      head->next = tail;
      tail->next = afterNext;

      head = afterNext;
      tail = parent[tail];
  }
}
