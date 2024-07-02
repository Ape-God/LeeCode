#include <iostream>
#include <vector>
#include <algorithm> // 用于 std::max
using namespace std;

// maxProfit函数用于计算最多k笔交易的最大利润
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        k = min(k, n / 2);
        vector<int> buy(k + 1);
        vector<int> sell(k + 1);

        buy[0] = -prices[0];
        sell[0] = 0;
        for (int i = 1; i <= k; ++i) {
            buy[i] = sell[i] = INT_MIN / 2;
        }

        for (int i = 1; i < n; ++i) {
            buy[0] = max(buy[0], sell[0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j] - prices[i]);
                sell[j] = max(sell[j], buy[j - 1] + prices[i]);
            }
        }

        return *max_element(sell.begin(), sell.end());
    }
};



int main() {
    std::vector<int> prices = { 2, 3, 6, 4, 0, 2, 2, 5 };
    int k = 3;
    Solution solution;
    int result = solution.maxProfit(k, prices);
    std::cout << "The maximum profit is: " << result << std::endl; // 应该输出 7
    return 0;
}