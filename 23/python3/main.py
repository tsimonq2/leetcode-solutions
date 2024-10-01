#!/usr/bin/env python3

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        nodes = []
        # Traverse all linked lists and store all nodes in the 'nodes' list
        for l in lists:
            while l:
                nodes.append(l)
                l = l.next

        # Sort all the nodes by value
        nodes.sort(key=lambda node: node.val)

        # Create a dummy node as the head
        dummy = ListNode()
        tail = dummy

        # Link the sorted nodes to form the merged linked list
        for node in nodes:
            tail.next = node
            tail = tail.next

        # Ensure the last node points to None
        tail.next = None

        return dummy.next
