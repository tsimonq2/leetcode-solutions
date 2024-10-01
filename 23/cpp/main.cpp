#include <iostream>
#include <vector>
#include <utility>

#include <vector>
#include <algorithm>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* return_head = new ListNode();
        ListNode* tail = return_head;
        std::vector<ListNode*> nodes;

        while (!lists.empty()) {
            // Traverse each linked list in 'lists'
            for (auto it = lists.begin(); it != lists.end(); /* no increment */) {
                if (*it == nullptr) {
                    // Erase lists that are empty (nullptr)
                    it = lists.erase(it);
                } else {
                    // Add the current node to 'nodes' and move to the next node in the list
                    nodes.emplace_back(*it);
                    *it = (*it)->next;
                    // Increment iterator after processing
                    if (*it == nullptr) {
                        it = lists.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }

        // Sort all nodes by value
        std::sort(nodes.begin(), nodes.end(), [](auto &left, auto &right) {
            return left->val < right->val;
        });

        // Create the final sorted list by linking the nodes
        for (ListNode* node : nodes) {
            tail->next = node;
            tail = tail->next;
        }

        // Ensure the last node points to nullptr
        tail->next = nullptr;

        return return_head->next;
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
