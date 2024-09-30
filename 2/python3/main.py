#!/usr/bin/env python3

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # Initialize variables
        return_node = ListNode()
        flag_node = return_node
        previous_node = None

        # Loop on each node
        while l1 or l2:
            # Set the value of the flag node
            total = flag_node.val
            if not l1:
                total += l2.val
                l2 = l2.next
            elif not l2:
                total += l1.val
                l1 = l1.next
            else:
                total += l1.val + l2.val
                l1 = l1.next
                l2 = l2.next

            remainder = 0
            if (total >= 10):
                remainder = total / 10
                total = total % 10
            flag_node.val = int(total)

            # Create the next node with the value of the remainder
            flag_node.next = ListNode(int(remainder))

            previous_node = flag_node
            flag_node = flag_node.next

        # If there is a trailing 0 on the flag node, remove it
        if flag_node.val == 0:
            previous_node.next = None

        return return_node     
