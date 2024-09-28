#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        if (nums.empty()) return 0;

        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            // Non-matching element
            if (nums[i] != val) {
                nums[n] = nums[i];
                n++;
            }
        }
        return n;
    }
};

int main() {
    Solution sol;

    // Test case 1: [3,2,2,3]
    std::vector<int> nums1 = {3,2,2,3};
    int val = 3;
    int result1 = sol.removeElement(nums1, val);
    std::cout << "Test 1: " << result1 << std::endl;
    std::cout << "Array after: ";
    for (int i = 0; i < result1; ++i) {
        std::cout << nums1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
