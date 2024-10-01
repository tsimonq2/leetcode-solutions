#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        // Use std::ranges::lower_bound and upper_bound
        auto first = std::ranges::lower_bound(nums, target);
        auto last = std::ranges::upper_bound(nums, target);

        // Initialize the result
        std::vector<int> result;
        result.reserve(2);

        if (first != nums.end() && *first == target) {
            result.emplace_back(std::distance(nums.begin(), first));
            result.emplace_back(std::distance(nums.begin(), last) - 1);
        } else {
            result = {-1, -1};
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
