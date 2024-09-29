#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        // Initialize a vector with rowIndex + 1 elements, all set to 1
        std::vector<int> row(rowIndex + 1, 1);

        // Update the row in-place from the second element to the second-to-last element
        for (int i = 1; i <= rowIndex; ++i) {
            // Update the row from right to left to avoid overwriting
            for (int j = i - 1; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }

        return row;
    }
};

// Helper function to print a row of Pascal's Triangle
void printRow(const std::vector<int>& row) {
    for (int num : row) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Test case 1: Get the 3rd row (0-indexed)
    std::cout << "Row 3 of Pascal's Triangle:" << std::endl;
    std::vector<int> result1 = solution.getRow(3);  // Outputs row at index 3: [1, 3, 3, 1]
    printRow(result1);

    // Test case 2: Get the 5th row (0-indexed)
    std::cout << "Row 5 of Pascal's Triangle:" << std::endl;
    std::vector<int> result2 = solution.getRow(5);  // Outputs row at index 5: [1, 5, 10, 10, 5, 1]
    printRow(result2);

    return 0;
}
