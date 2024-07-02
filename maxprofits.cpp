#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0; // 如果数组为空，返回0

        int maxProfit = 0;
        int minPrice = prices[0]; // 初始化最小价格为数组的第一个元素

        // 遍历价格数组
        for (int i = 1; i < prices.size(); ++i) {
            // 如果当前价格比记录的最小价格高，检查是否更新最大利润
            if (prices[i] > minPrice) {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
            else {
                // 如果当前价格更低，更新最小价格
                minPrice = prices[i];
            }
        }

        return maxProfit; // 返回最大利润
    }
};

int main() {
    Solution solution;
    vector<int> prices = { 7, 1, 5, 3, 6, 4 }; // 示例价格数组

    int result = solution.maxProfit(prices);
    cout << "The maximum profit from the stock transaction is: " << result << endl;

    return 0;
}