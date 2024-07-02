#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // 初始化为金额+1，表示未找到组合
        dp[0] = 0; // 金额为0时，不需要硬币

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    Solution solution;
    vector<int> coins = { 1, 2, 5 }; // 示例硬币数组
    int amount = 11; // 示例总金额

    int result = solution.coinChange(coins, amount);
    if (result == -1) {
        cout << "No combination of coins can sum up to the amount." << endl;
    }
    else {
        cout << "The minimum number of coins to form the amount is: " << result << endl;
    }

    return 0;
}