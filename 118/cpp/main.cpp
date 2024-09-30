#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> pascals_triangle;

        // Handle edge case for numRows <= 0
        if (numRows <= 0) {
            return pascals_triangle;
        }

        // Reserve space for the outer vector to avoid reallocations
        pascals_triangle.reserve(numRows);

        // First row is always {1}
        pascals_triangle.push_back({1});

        // Generate Pascal's Triangle row by row
        for (int i = 1; i < numRows; i++) {
            // Create and resize the row vector in one step
            std::vector<int> this_row(i + 1);
            // First and last element are always 1
            this_row[0] = 1;
            this_row[i] = 1;

            // Fill in the middle elements using the previous row
            for (int j = 1; j < i; j++) {
                this_row[j] = pascals_triangle[i-1][j-1] + pascals_triangle[i-1][j];
            }

            // Push the fully formed row into the triangle
            pascals_triangle.push_back(std::move(this_row));
        }

        return pascals_triangle;
    }
};

// Helper function to print Pascal's Triangle
void print_pascals_triangle(const std::vector<std::vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    Solution solution;

    // Test case 1: numRows = 5
    std::cout << "Pascal's Triangle for numRows = 5:\n";
    std::vector<std::vector<int>> result1 = solution.generate(5);
    print_pascals_triangle(result1);

    // Test case 2: numRows = 7
    std::cout << "\nPascal's Triangle for numRows = 7:\n";
    std::vector<std::vector<int>> result2 = solution.generate(7);
    print_pascals_triangle(result2);

    return 0;
}
