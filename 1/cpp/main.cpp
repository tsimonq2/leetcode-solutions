#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Store a value and its index, e.g. [1, 2, 3] -> {1: 0, 2: 1, 3: 2}
        std::unordered_map<int, int> number_map;

        // Iterate over nums
        for (int selected = 0; selected < nums.size(); ++selected) {
            // Instead of calculating sums, we work backwards from the target
            // and current value to find the complement that would match
            int complement = target - nums[selected];

            // If the complement exists in the map, return the pair of indices
            if (number_map.find(complement) != number_map.end()) {
                return {number_map[complement], selected};
            }

            // Otherwise, store the selected number and its index in the map
            number_map[nums[selected]] = selected;
        }

        // Not included in the task, but otherwise return nothing
        return {};
    }
};

int main() {
    Solution sol;

    // Test case 1: nums = [2,7,11,15], target = 9
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = sol.twoSum(nums1, target1);
    std::cout << "Test 1: [" << result1[0] << ", " << result1[1] << "]" << std::endl;

    // Test case 2: nums = [3,2,4], target = 6
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = sol.twoSum(nums2, target2);
    std::cout << "Test 2: [" << result2[0] << ", " << result2[1] << "]" << std::endl;

    // Test case 3: nums = [3,3], target = 6
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = sol.twoSum(nums3, target3);
    std::cout << "Test 3: [" << result3[0] << ", " << result3[1] << "]" << std::endl;

    return 0;
}
