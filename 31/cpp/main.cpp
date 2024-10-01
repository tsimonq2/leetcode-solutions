#include <iostream>
#include <algorithm>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        std::next_permutation(nums.begin(), nums.end());
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
