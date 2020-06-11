/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) //no possible swap
            return;
        
        ListNode* curr = head;  //look at node passed
        ListNode* prev = nullptr;   //used to look behind node passed
        
        while (curr->next != nullptr)   //move to last node in list
        {
            prev = curr;
            curr = curr->next;   
        }
        
        prev->next = nullptr; //This is the node before final node, it will no longer point to curr because it is being swapped
        ListNode* next = head->next;    //look at node next to head
        reorderList(next);  //recursively call to repeat on next node from head
        
        head->next = curr;  //make the next node to the last node
        curr->next = next;  //make last node point to node that was originally there
        
    }
};