#include <iostream>

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Edge case: If the list is empty or has only one element, return as is
        if (!head || !head->next) return head;

        // Initialize a dummy node that helps track the new head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (head && head->next) {
            // Nodes to be swapped
            ListNode* first = head;
            ListNode* second = head->next;

            // Swapping the pairs
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to the next pair
            prev = first;
            head = first->next;
        }

        return dummy->next;
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
