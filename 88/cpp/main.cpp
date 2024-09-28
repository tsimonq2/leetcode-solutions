#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        // Emptiness checks
        if ((nums1.size() == 0 && nums2.size() == 0) || (m == 0 && n == 0)) {
            nums1 = {};
            return;
        } else if (m == 0 && n > 0) {
            nums1 = nums2;
            return;
        } else if (n == 0 && m > 0) {
            return;
        }

        nums1.resize(m);
        nums2.resize(n);

        // Merge the two vectors into one
        int n1_index = 0;
        int n2_index = 0;
        std::vector<int> combined_nums;
        while (n1_index < m || n2_index < n) {
            if (n1_index >= m) {
                combined_nums.push_back(nums2[n2_index++]);
            } else if (n2_index >= n) {
                combined_nums.push_back(nums1[n1_index++]);
            } else if (nums1[n1_index] <= nums2[n2_index]) {
                combined_nums.push_back(nums1[n1_index++]);
            } else {
                combined_nums.push_back(nums2[n2_index++]);
            }
        }

        nums1 = combined_nums;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    std::vector<int> nums1_1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2_1 = {2, 5, 6};
    solution.merge(nums1_1, 3, nums2_1, 3);
    for (int num : nums1_1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Example 2
    std::vector<int> nums1_2 = {1};
    std::vector<int> nums2_2 = {};
    solution.merge(nums1_2, 1, nums2_2, 0);
    for (int num : nums1_2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example 3
    std::vector<int> nums1_3 = {0};
    std::vector<int> nums2_3 = {1};
    solution.merge(nums1_3, 0, nums2_3, 1);
    for (int num : nums1_3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
