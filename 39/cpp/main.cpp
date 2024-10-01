#include <iostream>
#include <vector>

class Solution {
public:
    // Public function that initializes the member variables and triggers backtracking
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        this->candidates = candidates;  // Store candidates in the class
        this->target = target;  // Store target in the class
        
        // Trigger the backtracking search starting with an empty combination
        std::vector<int> combination;
        backtrack(0, combination, 0);  // Start at index 0 and current sum of 0

        return results;  // Return the results after backtracking is complete
    }

private:
    // Member variables to store the public function arguments
    std::vector<int> candidates;
    int target;

    // Member variable to store the results
    std::vector<std::vector<int>> results;

    // Private backtracking function to find all combinations
    void backtrack(int i, std::vector<int>& current, int total) {
        const auto& candidates = this->candidates; // Local reference for faster access
        const int target = this->target;

        // Base case: if the current sum equals the target, add the combination to results
        if (total >= target || i >= candidates.size()) {
            if (total == target) {
                results.emplace_back(current); // Add valid combination to results
            }
            return;
        }

        current.emplace_back(candidates[i]);
        backtrack(i, current, total + candidates[i]);
        current.pop_back();
        backtrack(i + 1, current, total);
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
