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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        
        ListNode* curr = head;
        while (curr) {
            st.push(curr);
            curr = curr->next;
        }
        
        curr = head;
        
        while (curr) {
            ListNode* next = curr->next, * top = st.top();
            if (curr != top && next != top) {
                curr->next = top;
                curr->next->next = next;
                st.pop();
                st.top()->next = nullptr;
                curr = next;
            }
            else {
                curr = nullptr;
            }
        }
    }
};