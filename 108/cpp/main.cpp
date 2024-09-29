#include <iostream>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Deal with single-element, double-element, and empty vectors
        if (nums.size() == 0) {
            return nullptr;
        }

        // Get the middle element of the vector
        int root_index = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[root_index]);

        // Recursively construct the left subtree with the left half of the array
        vector<int> left_subarray(nums.begin(), nums.begin() + root_index);
        root->left = sortedArrayToBST(left_subarray);

        // Recursively construct the right subtree with the right half of the array
        vector<int> right_subarray(nums.begin() + root_index + 1, nums.end());
        root->right = sortedArrayToBST(right_subarray);

        return root;
    }
};

int main() {
    Solution sol;

    // Test case 1: [-10,-3,0,5,9]
    std::vector<int> nums1 = {-10,-3,0,5,9};
    TreeNode* result1 = sol.sortedArrayToBST(Y);
    std::cout << "Test 1: " << result1 << std::endl;

    return 0;
}
