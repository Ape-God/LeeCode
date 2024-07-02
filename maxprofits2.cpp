#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            // 如果今天的价格比昨天高，说明可以卖出昨天买入的股票
            if (prices[i] > prices[i - 1]) {
                // 加上利润，昨天买入今天卖出
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

int main() {
    Solution solution;
    vector<int> prices = { 7, 1, 5, 3, 6, 4 }; // 示例价格数组

    int result = solution.maxProfit(prices);
    cout << "The maximum profit from the stock transaction is: " << result << endl;

    return 0;
}