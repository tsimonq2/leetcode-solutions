#!/usr/bin/env python3

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        tail = head

        while (tail != None and tail.next != None):
            if (tail.val == tail.next.val):
                tail.next = tail.next.next
            else:
                tail = tail.next

        return head

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

head = build_linked_list([1,1,2])
sol = Solution()
merged = sol.deleteDuplicates(head)
print("Merged list:", linked_list_to_list(merged))

head = build_linked_list([1,1,2,3,3])
sol = Solution()
merged = sol.deleteDuplicates(head)
print("Merged list:", linked_list_to_list(merged))

head = build_linked_list([0,0,0,0,0,0])
sol = Solution()
merged = sol.deleteDuplicates(head)
print("Merged list:", linked_list_to_list(merged))
