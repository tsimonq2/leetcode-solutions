#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = 0;
        for (int i = 1; i < nums.size(); i++) {
            // Non-duplicate element
            if (nums[i] != nums[n]) {
                n++;
                nums[n] = nums[i];
            }
        }
        return n + 1;
    }
};

int main() {
    Solution sol;

    // Test case 1: [1,1,2]
    std::vector<int> nums1 = {1,1,2};
    int result1 = sol.removeDuplicates(nums1);
    std::cout << "Test 1: " << result1 << std::endl;
    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < result1; ++i) {
        std::cout << nums1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
