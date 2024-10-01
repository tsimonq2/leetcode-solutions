#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = INT_MAX / 100;
        int min_diff = closest;
        
        // Sort the array to allow two-pointer approach
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip the same element to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = std::abs(target - sum);
                
                if (diff < min_diff) {
                    // Set the closest sum
                    closest = sum;
                    min_diff = diff;
                }
                    
                // Move the pointers based on comparison with target
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    // If the sum is exactly the target, return it immediately
                    return sum;
                }
            }
        }
        
        return closest;
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
