#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

ListNode* swapPairs(ListNode* head) {
    
    ListNode* tmp = new ListNode(0, head);  //sets up prev node behind head
    ListNode* prev = tmp; //pointer to point at previous node
    ListNode* curr = head;  //looks at current node
        
    while(curr != nullptr && curr->next != nullptr) //while we have nodes to swap
    {
        prev->next = curr->next;    //make prev next to curr next
        prev = curr->next;  //set prev to curr next
            
        curr->next = prev->next;    //have curr next look at prev next
        prev->next = curr;  //set prev next to look back at curr
            
        prev = curr;    //move prev to curr
        curr = curr->next;  //move to next node from curr
            
           
    }
    return tmp->next;   //This is the head
}

//Used to test
int main()
{
    //creating list
    ListNode* n4 = new ListNode(5, nullptr);
    ListNode* n3 = new ListNode(4, n4);
    ListNode* n2 = new ListNode(3, n3);
    ListNode* n1 = new ListNode(2, n2);
    ListNode* head = new ListNode(1, n1);

    swapPairs(head);    //call function
    
    ListNode* travel = head;
    while(travel != nullptr)    //print list
    {
        cout << travel->val << " ";
        travel = travel->next;
    }
    cout << endl;
    return 0;
}