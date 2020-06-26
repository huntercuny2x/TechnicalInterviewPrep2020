# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next or not head.next.next:
            return 
        
        tail = None
        def reverse(head):
            nonlocal tail
            if not head.next:
                tail = head
                return
            temp = head.next
            head.next = None
            reverse(temp)
            temp.next = head
            return tail
        
        def get_middle(head):
            slow = head
            fast = head
            while fast.next and fast.next.next:
                slow = slow.next
                fast = fast.next.next
            return slow
        
        mid = get_middle(head).next
        cur = head
        while cur.next != mid:
            cur = cur.next
        
        cur.next = None
        reverse(mid)
        reversed_mid = tail
        
        def solution(head1, head2):
            if not head1 and not head2:
                return head1
            
            if not head1 and head2:
                return head2
            
            if not head2 and head1:
                return head1
            
            head2.next = solution(head1.next, head2.next)
            head1.next = head2
            return head1
        
        return solution(head, reversed_mid)

class Solution2:
    def reorderList(self, head: ListNode) -> None:
        d = {}
        i = 0
        cur = head
        while cur:
            d[i] = cur
            i += 1
            temp = cur.next
            cur.next = None
            cur = temp

        def solution(d, lo, hi):
            if lo == hi:
                return d[lo]

            if lo >= hi:
                return None

            d[lo].next = d[hi]
            d[hi].next = solution(d, lo+1, hi-1)
            return d[lo]


        solution(d, 0, i-1)
