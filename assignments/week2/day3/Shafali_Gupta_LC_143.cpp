//this doesn't work like it's supposed to on some test cases What my thinking was was to mkae the first element->next = last element. Then recusively do the same on the remaining elements. Then I set the remaining to the next of the last element. Not sure wh this doesn't work.


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
        if(head == nullptr || head->next == nullptr){
            return;
        }
        ListNode* n = head;
        while(n->next != nullptr){
            n = n->next;
        }
        // cout << n->val << '\n';
        ListNode* remain = head->next;
        ListNode * iter = remain;
        while(iter->next != nullptr&& iter->next->next!=nullptr){
            iter = iter->next;
        }
        iter ->next = nullptr;
        head->next = n;
        if(remain->next != nullptr){
             reorderList(remain);
        n->next = remain;
        }
        // reorderList(remain);
        // n->next = remain;
    }
};
