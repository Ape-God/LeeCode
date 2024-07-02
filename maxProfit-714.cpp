#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 主函数，用于计算最大利润
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        long long cash = 0, hold = -prices[0]; // 初始化状态：cash为0，hold为负的价格0

        for (int i = 1; i < n; ++i) {
            // 更新不持有股票的现金：可以是前一天不持有的现金，或者是将股票卖出得到的钱减去手续费
            cash = max(cash, hold + prices[i] - fee);
            // 更新持有股票的现金：可以是前一天持有的现金，或者是用不持有股票的现金减去当天的股票价格
            hold = max(hold, cash - prices[i]);
        }

        return static_cast<int>(cash); // 返回不持有股票的现金作为最大利润
    }
};

// 示例函数，用于演示 Solution 类的 maxProfit 方法
int main() {
    Solution solution;
    // 创建一个示例股票价格数组和手续费
    vector<int> prices = { 1, 3, 2, 8, 4, 9 };
    int fee = 2;
    // 调用 maxProfit 方法并输出结果
    cout << "Maximum profit: " << solution.maxProfit(prices, fee) << endl;

    return 0;
}