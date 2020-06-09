# 24. Swap Nodes in Pairs
# When I tried solving it without using an extra node in the beginning, but I would not get the right answer
# i.e if the input was [1,2,3,4], I'd get [1,3,2,4]. However, the swapping method is the same.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


def swapPairs(head):
  dummy = ListNode(0)
  # 0 -> LinkedList values
  dummy.next = head
  
  curr = dummy
  
  while curr.next and curr.next.next:
    ptr1 = curr.next
    ptr2 = curr.next.next
    
    curr.next = ptr2
    ptr1.next = ptr2.next
    ptr2.next = ptr1
    
    curr = curr.next.next
    
  return dummy.next
