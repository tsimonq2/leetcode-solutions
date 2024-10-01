#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort

class Solution {
public:
    // Public function that initializes the member variables and triggers backtracking
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
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
    void backtrack(int start, std::vector<int>& current, int total) {
        // Base case: if the current sum equals the target, add the combination to results
        if (total == target) {
            results.emplace_back(current);
            return;
        }

        // Iterate through candidates starting from 'start' index to avoid duplicates
        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates in the same recursive depth level
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            // If adding the current candidate exceeds the target, stop exploring further
            if (total + candidates[i] > target) break;

            // Include the current candidate
            current.emplace_back(candidates[i]);
            
            // Recur with the next index to avoid reusing the same candidate more than once
            backtrack(i + 1, current, total + candidates[i]);
            
            // Backtrack (remove last added element)
            current.pop_back();
        }
    }
};
