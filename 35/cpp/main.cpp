#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        // Define the initial search bounds
        int left = 0;
        int right = nums.size() - 1;

        // Binary search
        while (left <= right) {
            // Calculate the middle index to avoid overflow (using left + (right - left) / 2)
            int mid = left + (right - left) / 2;

            // Check if the middle element is the target value
            if (nums[mid] == target) {
                return mid;
            }

            // If target is greater than the middle element, discard the left half
            if (nums[mid] < target) {
                left = mid + 1;
            } 
            // If target is smaller than the middle element, discard the right half
            else {
                right = mid - 1;
            }
        }

        // If we exit the loop, the target was not found in the array
        return left;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1,3,5,6};

    // Test case 1: [1,3,5,6], 5
    int result1 = sol.searchInsert(nums, 5);
    std::cout << "Test 1: " << result1 << std::endl;

    // Test case 2: [1,3,5,6], 2
    int result2 = sol.searchInsert(nums, 2);
    std::cout << "Test 2: " << result2 << std::endl;

    // Test case 3: [1,3,5,6], 7
    int result3 = sol.searchInsert(nums, 7);
    std::cout << "Test 3: " << result3 << std::endl;

    return 0;
}
