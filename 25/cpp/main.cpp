#include <iostream>

class Solution {
public:
    // Helper function to check if there are at least k nodes left
    bool hasKNodes(ListNode* node, int k) {
        while (node && k > 0) {
            node = node->next;
            k--;
        }
        return k == 0;
    }

    // Helper function to reverse k nodes and return the new head and next segment
    ListNode* reverseKNodes(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (k > 0) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
            k--;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // Dummy node to simplify edge cases and tracking
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev_tail = dummy;

        while (hasKNodes(head, k)) {
            // Reverse the next k nodes
            ListNode* next_segment = head;
            for (int i = 0; i < k; ++i) {
                next_segment = next_segment->next;
            }

            // Reverse the current k-group
            ListNode* new_head = reverseKNodes(head, k);

            // Connect the previous part with the newly reversed segment
            prev_tail->next = new_head;

            // Move prev_tail to the end of the reversed segment
            prev_tail = head;
            head = next_segment;
        }

        // Connect the remaining part of the list (if fewer than k nodes left)
        prev_tail->next = head;

        return dummy->next;
    }
};
