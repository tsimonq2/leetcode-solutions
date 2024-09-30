#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::set<std::set<int>> triplets;
        if (nums.size() < 3) { return {}; }

        // Three flags
        int right = 2;
        for (int left = 0; left + 2 < nums.size(); left++) {
            for (int middle = left + 1; middle + 1 < nums.size(); middle++) {
                for (int right = middle + 1; right < nums.size(); right++) {
                    if (nums[left] + nums[middle] + nums[right] == 0) {
                        triplets.insert({nums[left], nums[middle], nums[right]});
                    }
                }
            }
        }

        // Convert set of sets to vector of vectors
        std::vector<std::vector<int>> result;
        for (const auto& triplet : triplets) {
            result.push_back(std::vector<int>(triplet.begin(), triplet.end()));
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
