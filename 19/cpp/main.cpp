#include <iostream>
#include <stack>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* return_head = head;
        std::stack<ListNode*> stack;

        while (head != nullptr) {
            stack.push(&head);
            head = head->next;
        }

        for (int i = 1; i <= n; i++) {
            stack.pop();
        }

        // If the stack is empty, it means we are removing the head node
        if (stack.empty()) {
            // Return the next node as the new head
            return return_head->next;
        }

        ListNode* end_normal = stack.top();
        end_normal->next = end_normal->next->next;

        return return_head;
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
