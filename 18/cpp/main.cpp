#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        
        // Sort the array to allow two-pointer approach
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate elements for the first pointer
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < nums.size(); j++) {
                // Skip duplicate elements for the second pointer
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Two-pointer approach for the remaining two numbers
                int left = j + 1;
                int right = nums.size() - 1;
                
                while (left < right) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        // Add the quadruplet to the result
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for left and right pointers
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
