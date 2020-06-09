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
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        //I am apporaching this like swapping elements of an array where i, i+1 -> i+1, 1 and we double increment to go through the array, but with list node and pointers instead 
        //make next node pointed to rn point to current node instead
        //store what the next node points to & what that next node's next node pointed to and set that to poitn now node 
        
        //first establish correct head 
        ListNode * correctHead = head->next;
        
        //traverse the list 
        while(head->next != nullptr)
        {
            //let just access the values we need 
            ListNode * tempI = head; //i
            ListNode * tempI1 = head->next; //i + 1
            ListNode * tempI1swapPointer = tempI1->next->next; // i + 1's next next which i points to after swapping 
            
            head = tempI1; //head is set to i+1
            head->next = tempI;//i+1 is head now pointing to i
            tempI->next = tempI1swapPointer; //i is pointing to og i+1's next next which we should do 
            
            
            head = head->next->next;  //increment 2x right?      
            
            //this has to have like a ton of memory errors 
        }
        
        return correctHead;
    }
};
