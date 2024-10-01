#include <cmath>
#include <iostream>

class Solution {                                                                                                                                                            
public:                                                                                                                                                                     
    int trap(std::vector<int>& height) {
        int flag_left = 0, flag_right = height.size() - 1;
        int max_left = 0, max_right = 0;
        int total = 0;
        
        // Two-pointer approach to calculate trapped water
        while (flag_left <= flag_right) { 
            // If left height is less than or equal to right, process the left side
            if (height[flag_left] <= height[flag_right]) {
                max_left = std::max(max_left, height[flag_left]);
                total += max_left - height[flag_left];
                flag_left++;
            } 
            // Otherwise, process the right side
            else {                                                                                                                                                        
                max_right = std::max(max_right, height[flag_right]);
                total += max_right - height[flag_right];
                flag_right--;
            }
        }
        return total;
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
