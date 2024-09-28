#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged = new ListNode();
        ListNode* tail = merged;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Append the remaining nodes of the non-empty list
        if (list1 != nullptr) {
            tail->next = list1;
        } else if (list2 != nullptr) {
            tail->next = list2;
        }

        // Return the merged list
        return merged->next;
    }
};


// Helper function to create a linked list from an array
ListNode* createLinkedList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    Solution sol;

    // Example 1: list1 = [1, 2, 4], list2 = [1, 3, 4]
    ListNode* list1 = createLinkedList({1, 2, 4});
    ListNode* list2 = createLinkedList({1, 3, 4});
    ListNode* mergedList = sol.mergeTwoLists(list1, list2);
    printLinkedList(mergedList);  // Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> nullptr

    // Example 2: list1 = [], list2 = []
    ListNode* list3 = createLinkedList({});
    ListNode* list4 = createLinkedList({});
    mergedList = sol.mergeTwoLists(list3, list4);
    printLinkedList(mergedList);  // Output: nullptr

    // Example 3: list1 = [], list2 = [0]
    ListNode* list5 = createLinkedList({});
    ListNode* list6 = createLinkedList({0});
    mergedList = sol.mergeTwoLists(list5, list6);
    printLinkedList(mergedList);  // Output: 0 -> nullptr

    return 0;
}
