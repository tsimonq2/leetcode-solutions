#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(const std::string& s) {
        // Statically-set Roman Numeral values
        std::unordered_map<char, int> romanNumerals = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int value = 0;
        int n = s.size();

        // Iterate over the string
        for (int i = 0; i < n; ++i) {
            int current = romanNumerals[s[i]];
            int next = (i < n - 1) ? romanNumerals[s[i + 1]] : 0;

            // Subtract if the current numeral is less than the next, otherwise add it
            if (current < next) {
                value -= current;
            } else {
                value += current;
            }
        }

        return value;
    }
};

int main() {
    Solution sol;

    // Test case 1: III -> 3
    int result1 = sol.romanToInt("III");
    std::cout << "Test 1: " << result1 << std::endl;

    // Test case 2: LVIII -> 58
    int result2 = sol.romanToInt("LVIII");
    std::cout << "Test 2: " << result2 << std::endl;

    // Test case 3: MCMXCIV -> 1994
    int result3 = sol.romanToInt("MCMXCIV");
    std::cout << "Test 3: " << result3 << std::endl;

    return 0;
}
