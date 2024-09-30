#include <iostream>
#include <vector>
#include <utility>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Emptyness check
        if (nums1.empty() && nums2.empty()) { return 0; }

        double result;
        // If each vector only has one element, return the average
        if (nums1.size() == 1 && nums2.size() == 1) {
            result = (nums1[0] + nums2[0]) / 2.0;
            return result;
        }
        int combined_size = nums1.size() + nums2.size();
        int median_index = static_cast<int>(combined_size / 2);
        int combined_nums[median_index];
        int nums1_tail = 0, nums2_tail = 0;
        for (int i = 0; i <= median_index; i++) {
            // If we are at the end of either list, only add the non-empty list
            // There will not be a case where both are at the end
            if (nums1_tail >= nums1.size()) {
                combined_nums[i] = nums2[nums2_tail];
                nums2_tail++;
            } else if (nums2_tail >= nums2.size()) {
                combined_nums[i] = nums1[nums1_tail];
                nums1_tail++;
            } else if (nums1[nums1_tail] > nums2[nums2_tail]) {
                combined_nums[i] = nums2[nums2_tail];
                nums2_tail++;
            } else {
                combined_nums[i] = nums1[nums1_tail];
                nums1_tail++;
            }
        }

        // If the combined size is even, average the last two elements
        // If the combined size is odd, just return the last element
        if (combined_size % 2 == 0) {
            result = static_cast<double>((combined_nums[median_index] + combined_nums[median_index - 1]) / 2.0);
        } else {
            result = static_cast<double>(combined_nums[median_index - 1]);
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1, nums2;
    double result;

    // Test case 1: nums1 = [1,3], nums2 = [2]
    nums1 = {1,3};
    nums2 = {2};
    result = sol.findMedianSortedArrays(nums1, nums2);
    std::cout << "Test 1: " << result << std::endl;

    // Test case 2: nums1 = [1,2], nums2 = [3,4]
    nums1 = {1,2};
    nums2 = {3,4};
    result = sol.findMedianSortedArrays(nums1, nums2);
    std::cout << "Test 2: " << result << std::endl;

    return 0;
}
