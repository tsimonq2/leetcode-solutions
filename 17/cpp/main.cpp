#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        const std::unordered_map<char, std::string> digit_letters = {
            {'2', "abc"},  // 2 -> a, b, c
            {'3', "def"},  // 3 -> d, e, f
            {'4', "ghi"},  // 4 -> g, h, i
            {'5', "jkl"},  // 5 -> j, k, l
            {'6', "mno"},  // 6 -> m, n, o
            {'7', "pqrs"}, // 7 -> p, q, r, s
            {'8', "tuv"},  // 8 -> t, u, v
            {'9', "wxyz"}  // 9 -> w, x, y, z
        };

        std::vector<std::string> results;

        // Iterate on each input digit
        for (char c : digits) {
            std::vector<std::string> new_results;
            // Iterate on the digit letters
            for (char l : digit_letters.at(c)) {
                // On the first round of the outer for loop, create new values
                if (results.empty()) {
                    new_results.emplace_back(1, l);
                } else {
                    // Now that we have a base size, start reserving exact space
                    new_results.reserve(results.size() * new_results.size());
                    // Loop on every single existing element and add this char to the end
                    for (int i = 0; i < results.size(); i++) {
                        new_results.emplace_back(results[i] + l);
                    }
                }
            }
            results.swap(new_results);
        }

        return results;
    }
};

int main() {
    Solution sol;

    // Test case X: Y
    RETURN_TYPE resultX = sol.FUNCTION_NAME(Y);
    std::cout << "Test X: " << resultX << std::endl;

    return 0;
}
