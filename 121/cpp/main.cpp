#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_profit = 0;
        int min_price = prices[0];

        for (int& current_price : prices) {
            max_profit = std::max(max_profit, current_price - min_price);
            min_price = std::min(min_price, current_price);
        }

        return max_profit;
    }
};

int main() {
    Solution solution;

    std::vector<int> prices1 = {7,1,5,3,6,4};
    std::cout << solution.maxProfit(prices1) << "\n";

    std::vector<int> prices2 = {7,6,4,3,1};
    std::cout << solution.maxProfit(prices2) << "\n";

    return 0;
}
