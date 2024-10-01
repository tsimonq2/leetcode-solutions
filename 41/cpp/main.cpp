#include <iostream>

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missing_positive = 1;
        std::set<int> num_set(nums.begin(), nums.end());
        for (int num : num_set) {
            if (num == missing_positive) {
                missing_positive++;
            } else if (num > missing_positive) {
                break;
            }
        }
        return missing_positive;
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
