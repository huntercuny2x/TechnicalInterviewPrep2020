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
        if ( ! head ) {
            return head;
        }
        
        ListNode* prev = nullptr, * curr = head;
        head = curr->next ? curr->next : curr;
        
        while (curr && curr->next) {
            ListNode* next = curr->next, * temp = curr;
            cout << curr->val << " : " << next->val << endl;
            curr = next;
            temp->next = curr->next;
            curr->next = temp;
            
            if (prev) {
                prev->next = curr;
            }
            prev = temp;
            
            curr = temp->next;
        }
        
        return head;
    }
};