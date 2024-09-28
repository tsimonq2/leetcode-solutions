#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Store the origin node, we will return this later
        ListNode* tail = head;

        while (tail != nullptr && tail->next != nullptr) {
            // If the current head and next head have the same values, keep
            // going until we find a different value
            if (tail->val == tail->next->val) {
                tail->next = tail->next->next;
            } else {
                tail = tail->next;
            }
        }

        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Test Case 1: head = [1, 1, 2]
    ListNode* head1 = new ListNode(1, new ListNode(1, new ListNode(2)));
    std::cout << "Original List 1: ";
    printList(head1);
    ListNode* deduplicated1 = solution.deleteDuplicates(head1);
    std::cout << "Deduplicated List 1: ";
    printList(deduplicated1);

    // Test Case 2: head = [1, 1, 2, 3, 3]
    ListNode* head2 = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    std::cout << "Original List 2: ";
    printList(head2);
    ListNode* deduplicated2 = solution.deleteDuplicates(head2);
    std::cout << "Deduplicated List 2: ";
    printList(deduplicated2);

    // Test Case: head = [0, 0, 0, 0, 0]
    ListNode* head3 = new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0)))));
    std::cout << "Original List 3: ";
    printList(head3);
    ListNode* deduplicated3 = solution.deleteDuplicates(head3);
    std::cout << "List after removing duplicates: ";
    printList(deduplicated3);

    return 0;
}
