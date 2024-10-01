#!/usr/bin/env python3

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # Helper function to check if there are at least k nodes left
        def has_k_nodes(cur, k):
            count = 0
            while cur and count < k:
                cur = cur.next
                count += 1
            return count == k
        
        # Helper function to reverse k nodes and return the new head and the next segment
        def reverse_k_nodes(head, k):
            prev = None
            cur = head
            while k > 0:
                next_node = cur.next
                cur.next = prev
                prev = cur
                cur = next_node
                k -= 1
            return prev, cur

        # Dummy node to simplify edge case handling
        dummy = ListNode(0)
        dummy.next = head
        prev_tail = dummy

        while has_k_nodes(head, k):
            # Reverse the next k nodes
            new_head, next_segment = reverse_k_nodes(head, k)
            
            # Connect the previous part with the newly reversed segment
            prev_tail.next = new_head
            
            # Move prev_tail to the end of the reversed segment (which is now 'head')
            prev_tail = head
            head = next_segment

        # Connect the remaining part of the list (if fewer than k nodes left)
        prev_tail.next = head

        return dummy.next
