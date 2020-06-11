# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import math

def reorder_list(head):
  """
  Do not return anything, modify head in-place instead.
  """
  length = list_len(head)
  curr = head
  half = math.ceil(length / 2)
  itr = 0
  
  # split the linked list into two
  # the first half contains everything up to the mid including the mid
  # the other half contains the rest
  # we need to reverse the other half
  
  # then we take first node in first half and connect it to first node of second half
  # and then continue
  # if odd, then first half > other half, so we can just add first_half[-1] to the final linked list
  
  #while itr < half and curr:
    
    
  
  
  
def list_len(head):
  l = 0
  curr = head
  while curr:
    l += 1
    curr = curr.next
    
  return l