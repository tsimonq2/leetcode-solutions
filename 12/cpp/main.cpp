#include <iostream>
#include <array>
#include <string>
#include <utility>

class Solution {
public:
    std::string intToRoman(int num) {
        // Statically-set Roman Numeral values
        constexpr std::array<std::pair<const char*, int>, 13> romanNumerals = {{
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
            {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
            {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
        }};

        std::string result;

        // Iterate over the integer
        for (int i = 0; i <= 12; i++) {
            while (num >= romanNumerals[i].second) {
                result += romanNumerals[i].first;
                num -= romanNumerals[i].second;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1: 3749
    std::string result1 = sol.intToRoman(3749);
    std::cout << "Test 1: " << result1 << std::endl;

    // Test case 2: 58
    std::string result2 = sol.intToRoman(58);
    std::cout << "Test 2: " << result2 << std::endl;

    // Test case 3: 1994
    std::string result3 = sol.intToRoman(1994);
    std::cout << "Test 3: " << result3 << std::endl;

    return 0;
}
