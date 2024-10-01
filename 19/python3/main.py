#!/usr/bin/env python3

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # Use a stack to store pointers to the nodes
        stack = []
        current = head

        # Push each node onto the stack
        while current:
            stack.append(current)
            current = current.next

        # Pop n nodes from the stack to find the nth node from the end
        for _ in range(n):
            stack.pop()

        # If the stack is empty, we're removing the head node
        if not stack:
            return head.next

        # Get the node before the nth node from the end
        node_before_nth = stack[-1]

        # Remove the nth node from the end
        node_before_nth.next = node_before_nth.next.next

        return head
