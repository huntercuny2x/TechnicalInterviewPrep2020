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
    void reorderList(ListNode* head) 
    {
        //a bad but possible way to do it is storing an array of pointers 
        vector<ListNode*> arrOfNodes;
     
        ListNode * iterator = head;
        while(iterator != nullptr)
        {
            arrOfNodes.push_back(iterator);
            iterator = iterator->next;
        }        
        
        int i = 1;
        while(i < (arrOfNodes.size()/2))
        {
            swap(arrOfNodes[i], arrOfNodes[arrOfNodes.size()-i]);
            i++;
        }
        //do a manual swap of last element with the "mid"
        swap(arrOfNodes[i], arrOfNodes[arrOfNodes.size()-1]);
        
        //by here we have the proper algoritm for swaps, & the arrOfNodes has the proper line up just put it into linked list 
        
        int indexInArr = 1;
        while(indexInArr < arrOfNodes.size())
        {
            head->next = arrOfNodes[indexInArr];
            head = head->next;
            indexInArr++;
        }
        
        for(int j = 0; j < arrOfNodes.size(); j++)
        {
            cout << arrOfNodes[j] << " "; 
        }
        //i couted, the things are position right but i need to lower big O, but this works, try daniel way
    
        /*        
        //get length and mid of list
        //split into first and last halves
        //reverse the last half
            //have temp, current and prev pointers
            //traverses: put next as next, set previous as curr next fix head and iterate forward
        //only traverse the last half and add it to the front, move head of last to next  
        //when adding to og list have a pointer of where are index wise 

        ListNode * iterator = head; //used to iterate
        int listSize = 0; //will give us size of list
        int listMid = 0; //will be mid of list
        
        while(iterator != nullptr)
        {
            iterator = iterator->next;
            listSize++;
        }        
        
        listMid = listSize/2;
        
        cout << listSize;
        
        */
    }
};
