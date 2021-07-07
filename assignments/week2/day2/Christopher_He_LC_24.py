# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        def solution(head):
            if not (head and head.next):
                return head
            
            recurse = solution(head.next.next)
            
            temp = head.next
            head.next = recurse
            temp.next = head
            return temp
        return solution(head)
