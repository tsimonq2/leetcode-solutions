#!/usr/bin/env python3

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        merged = ListNode()
        tail = merged

        # Traverse both lists and merge them
        while list1 and list2:
            # Compare the current nodes of both lists
            if list1.val < list2.val:
                tail.next = list1  # Add list1's node to the merged list
                list1 = list1.next  # Move to the next node in list1
            else:
                tail.next = list2  # Add list2's node to the merged list
                list2 = list2.next  # Move to the next node in list2
            tail = tail.next  # Move the tail pointer

        # If there are any remaining nodes in either list, append them
        if list1:
            tail.next = list1
        elif list2:
            tail.next = list2

        # The merged list starts at merged.next
        return merged.next

# Helper function to convert a Python list into a linked list
def build_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

# Helper function to convert a linked list back to a Python list (for easy verification)
def linked_list_to_list(node):
    result = []
    while node:
        result.append(node.val)
        node = node.next
    return result

# Example 1: list1 = [1, 2, 4], list2 = [1, 3, 4]
list1 = build_linked_list([1, 2, 4])
list2 = build_linked_list([1, 3, 4])
sol = Solution()
merged = sol.mergeTwoLists(list1, list2)
print("Merged list:", linked_list_to_list(merged))  # Output: [1, 1, 2, 3, 4, 4]

# Example 2: list1 = [], list2 = []
list1 = build_linked_list([])
list2 = build_linked_list([])
merged = sol.mergeTwoLists(list1, list2)
print("Merged list:", linked_list_to_list(merged))  # Output: []

# Example 3: list1 = [], list2 = [0]
list1 = build_linked_list([])
list2 = build_linked_list([0])
merged = sol.mergeTwoLists(list1, list2)
print("Merged list:", linked_list_to_list(merged))  # Output: [0]
