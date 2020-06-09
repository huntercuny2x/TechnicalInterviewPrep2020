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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == nullptr || head ->next == nullptr)
            return head;
        

        ListNode* itr = head;
        ListNode* prev = head;
        ListNode*ahead = head->next->next;
        
        head = head->next;
        head->next = prev;
         
        itr = ahead;
        
        while(ahead != nullptr && ahead -> next != nullptr){
            ahead = ahead->next->next;
            prev->next = itr->next;
            prev = itr;
            itr->next->next = itr;
            itr = ahead;

        }
        
        prev -> next = nullptr;
        
        return head;
             
    }
        
};
