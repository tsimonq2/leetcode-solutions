#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int index = digits.size() - 1;

        if (digits[index] < 9) {
            digits[index]++;
            return digits;
        }

        while (index >= 0 && digits[index] == 9) {
            digits[index] = 0;
            index--;
        }
        if (index >= 0) {
            digits[index]++;
        } else {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main() {
    Solution sol;

    std::vector<int> digits1 = {1, 2, 3};
    std::vector<int> result1 = sol.plusOne(digits1);
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> digits2 = {4, 3, 2, 1};
    std::vector<int> result2 = sol.plusOne(digits2);
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> digits3 = {9};
    std::vector<int> result3 = sol.plusOne(digits3);
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
