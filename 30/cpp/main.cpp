#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        // Return nothing if words or s is empty
        if (s.empty() || words.empty()) {
            return {};
        }

        std::size_t chunk_size = words[0].size();
        int substring_size = words.size() * chunk_size;
        
        // If the length of any candidate substring exceeds the total length, return
        if (substring_size > s.size()) {
            return {};
        }

        // Check if all words and the string are made of the same repeated character
        bool is_repeated = true;
        char first_char = s[0];
        for (const std::string& word : words) {
            if (word != std::string(chunk_size, first_char)) {
                is_repeated = false;
                break;
            }
        }
        if (is_repeated) {
            for (char c : s) {
                if (c != first_char) {
                    is_repeated = false;
                    break;
                }
            }
        }
        
        if (is_repeated) {
            // Special case for repeated characters
            std::vector<int> result;
            for (int i = 0; i <= s.size() - substring_size; ++i) {
                if (s.substr(i, substring_size) == std::string(substring_size, first_char)) {
                    result.push_back(i);
                }
            }
            return result;
        }

        // Create a frequency map of the words
        std::unordered_map<std::string, int> word_count;
        for (const auto& word : words) {
            word_count[word]++;
        }

        std::vector<int> result;

        // Sliding window over the string `s`
        for (int i = 0; i <= s.size() - substring_size; ++i) {
            std::unordered_map<std::string, int> seen;
            int j = 0;

            // Check each word in the current window
            for (; j < words.size(); ++j) {
                std::string current_word = s.substr(i + j * chunk_size, chunk_size);

                // If the word is not in the word list, break
                if (word_count.find(current_word) == word_count.end()) {
                    break;
                }

                seen[current_word]++;

                // If we see a word more times than it appears in `words`, break
                if (seen[current_word] > word_count[current_word]) {
                    break;
                }
            }

            // If all words are matched, add the start index
            if (j == words.size()) {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    std::string s1 = "barfoothefoobarman";
    std::vector<std::string> words1 = {"foo", "bar"};
    std::vector<int> result1 = solution.findSubstring(s1, words1);
    for (int idx : result1) std::cout << idx << " ";  // Expected Output: 0 9
    std::cout << std::endl;

    // Test case 2
    std::string s2 = "wordgoodgoodgoodbestword";
    std::vector<std::string> words2 = {"word","good","best","good"};
    std::vector<int> result2 = solution.findSubstring(s2, words2);
    for (int idx : result2) std::cout << idx << " ";  // Expected Output: 0 9
    std::cout << std::endl;

    // Test case 3
    std::string s3 = "wordgoodgoodgoodbestword";
    std::vector<std::string> words3 = {"word","good","best","word"};
    std::vector<int> result3 = solution.findSubstring(s3, words3);
    for (int idx : result3) std::cout << idx << " ";  // Expected Output: 0 9
    std::cout << std::endl;

    // Test case 4
    std::string s4 = "ababaab";
    std::vector<std::string> words4 = {"ab","ba","ba"};
    std::vector<int> result4 = solution.findSubstring(s4, words4);
    for (int idx : result4) std::cout << idx << " ";  // Expected Output: 0 9
    std::cout << std::endl;

    return 0;
}
