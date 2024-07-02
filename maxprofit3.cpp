#include <iostream>
#include <vector>
#include <algorithm> // 用于 std::max 和 std::min
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};


int main() {
    std::vector<int> prices = { 3, 3, 5, 0, 0, 3, 1, 4 };
    Solution solution;
    int result = solution.maxProfit(prices);
    std::cout << "The maximum profit is: " << result << std::endl; // 应该输出 6
    return 0;
}