#include <iostream>
#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        // Start with the first sequence
        std::string result = "1";

        // Build the sequence up to the nth term
        for (int i = 2; i <= n; ++i) {
            std::string current = "";  // Store the current sequence

            // Iterate through the previous sequence to count and describe
            for (std::size_t j = 0; j < result.length(); ++j) {
                int count = 1;

                // Count the number of consecutive identical digits
                while (j + 1 < result.length() && result[j] == result[j + 1]) {
                    ++count;
                    ++j;
                }

                // Append the count and the digit to the current sequence
                current += std::to_string(count) + result[j];
            }

            // Update result to the current sequence for the next iteration
            result = current;
        }

        return result;
    }
};
