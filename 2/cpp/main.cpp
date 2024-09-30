#include <iostream>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Initialize variables
        ListNode* return_node = new ListNode();
        ListNode* flag_node = return_node;
        ListNode* previous_node;

        // Loop on each node
        while (l1 != nullptr || l2 != nullptr) {
            // Set the value of the flag node
            int total = flag_node->val;
            if (l1 == nullptr) {
                total += l2->val;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                total += l1->val;
                l1 = l1->next;
            } else {
                total += l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }

            int remainder = 0;
            if (total >= 10) {
                remainder = total / 10;
                total = total % 10;
            }
            flag_node->val = total;

            // Create the next node with the value of the remainder
            flag_node->next = new ListNode(remainder);

            previous_node = flag_node;
            flag_node = flag_node->next;
        }

        // If there is a trailing 0 on the flag node, remove it
        if (flag_node->val == 0) {
            previous_node->next = nullptr;
        }

        return return_node;
    }
};

// Helper function to print the linked list.
void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next != nullptr) std::cout << " -> ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Test Case 1: l1 = [2,4,3], l2 = [5,6,4]
    ListNode* l1_1 = new ListNode(2, new ListNode(4, new ListNode(3)));  // 2 -> 4 -> 3
    ListNode* l2_1 = new ListNode(5, new ListNode(6, new ListNode(4)));  // 5 -> 6 -> 4
    ListNode* result_1 = solution.addTwoNumbers(l1_1, l2_1);
    std::cout << "Test Case 1: ";
    printList(result_1);  // Expected output: 7 -> 0 -> 8

    // Test Case 2: l1 = [0], l2 = [0]
    ListNode* l1_2 = new ListNode(0);  // 0
    ListNode* l2_2 = new ListNode(0);  // 0
    ListNode* result_2 = solution.addTwoNumbers(l1_2, l2_2);
    std::cout << "Test Case 2: ";
    printList(result_2);  // Expected output: 0

    // Test Case 3: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    ListNode* l1_3 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));  // 9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9
    ListNode* l2_3 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));  // 9 -> 9 -> 9 -> 9
    ListNode* result_3 = solution.addTwoNumbers(l1_3, l2_3);
    std::cout << "Test Case 3: ";
    printList(result_3);  // Expected output: 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1

    return 0;
}
