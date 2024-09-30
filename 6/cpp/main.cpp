#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Edge cases/single row
        if (numRows <= 0) {
            return "";
        } else if (numRows == 1) {
            return s;
        }

        // Practically speaking, this is Q2 of a Cartesian plane, assume all Y
        // values are negative (even though they are not)
        std::unordered_map<int, std::unordered_map<int, std::unique_ptr<char>>> plane;
        std::pair<int, int> current_pos = {1,1};
        std::pair<int, int> outer_bounds = {1,1};
        // Diagonal is up and over by 1
        bool diagonal = false;
        for (char c : s) {
            // Assign the character
            plane[current_pos.first][current_pos.second] = std::make_unique<char>(c);
            if (current_pos.first > outer_bounds.first) {
                outer_bounds.first = current_pos.first;
            } else if (current_pos.second > outer_bounds.second) {
                outer_bounds.second = current_pos.second;
            }

            // If we are going straight down, simply assign the value and continuw
            if (!diagonal && current_pos.second < numRows) {
                current_pos.second++;
            }
            // At the last row, start going diagonally (up one, over one)
            else if (!diagonal && current_pos.second == numRows) {
                diagonal = true;
                current_pos.first++;
                current_pos.second--;
            }
            // Keep going diagonally until we hit the top
            else if (diagonal && current_pos.second > 1) {
                current_pos.first++;
                current_pos.second--;
            }
            // Once we hit the top, start at the beginning
            else if (diagonal && current_pos.second == 1) {
                current_pos.second++;
                diagonal = false;
            }
        }

        // Convert the plane into a string
        std::string result = "";
        for (int y = 1; y <= outer_bounds.second; y++) {
            for (int x = 1; x <= outer_bounds.first; x++) {
                auto it_x = plane.find(x);
                if (it_x != plane.end()) {
                    auto it_y = it_x->second.find(y);
                    if (it_y != it_x->second.end()) {
                        result += *it_y->second.get();
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1: s = "PAYPALISHIRING", numRows = 3
    std::string result1 = sol.convert("PAYPALISHIRING", 3);
    std::cout << "Test 1: " << std::endl << result1 << std::endl;

    // Test case 2: s = "PAYPALISHIRING", 4
    std::string result2 = sol.convert("PAYPALISHIRING", 4);
    std::cout << "Test 2: " << std::endl << result2 << std::endl;

    // Test case 3: s = "A", 1
    std::string result3 = sol.convert("PAYPALISHIRING", 1);
    std::cout << "Test 3: " << std::endl << result3 << std::endl;

    return 0;
}
