void reorderList(ListNode* head) 
{
    if(head == nullptr) 
    {
        return;
    }
    
    ListNode* pre = head;
    ListNode* post = head->next;
    
    while(post && post->next)
    { 
        post = post->next->next;
        pre = pre->next;
    }
    
    stack<ListNode*> nodes;
    ListNode* one = head;
    ListNode* two = pre->next;
    pre->next = nullptr;
    
    while(two != nullptr)
    {
        nodes.push(two);
        two = two->next;
    }

    while(!nodes.empty())
    {
        ListNode* top = nodes.top();
        nodes.pop();
        top->next = one->next;
        one->next = top;
        one = one->next->next;
    }
}


