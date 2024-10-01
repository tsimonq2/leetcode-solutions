#!/usr/bin/env python3

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        # Edge case: if the list is empty or has only one node
        if not head or not head.next:
            return head

        # Dummy node to simplify edge case handling
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        while head and head.next:
            # Nodes to be swapped
            first = head
            second = head.next

            # Swapping the pairs
            first.next = second.next
            second.next = first
            prev.next = second

            # Move to the next pair
            prev = first
            head = first.next

        return dummy.next
