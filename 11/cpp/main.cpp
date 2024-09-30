#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            // Height * width
            int current_area = std::min(height[left], height[right]) * (right - left);
            if (current_area > max_area) { max_area = current_area; }
            if (height[left] > height[right]) {
                right--;
            } else if (height[left] <= height[right]) {
                left++;
            }
        }

        return max_area;
    }
};

int main() {
    Solution sol;
    std::vector<int> data;
    int result;

    // Test case 1: [1,8,6,2,5,4,8,3,7]
    data = {1,8,6,2,5,4,8,3,7};
    result = sol.maxArea(data);
    std::cout << "Test 1: " << result << std::endl;

    // Test case 2: [1,1]
    data = {1,1};
    result = sol.maxArea(data);
    std::cout << "Test 2: " << result << std::endl;

    return 0;
}
