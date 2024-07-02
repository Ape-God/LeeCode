#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // ��ʼ��Ϊ���+1����ʾδ�ҵ����
        dp[0] = 0; // ���Ϊ0ʱ������ҪӲ��

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
    vector<int> coins = { 1, 2, 5 }; // ʾ��Ӳ������
    int amount = 11; // ʾ���ܽ��

    int result = solution.coinChange(coins, amount);
    if (result == -1) {
        cout << "No combination of coins can sum up to the amount." << endl;
    }
    else {
        cout << "The minimum number of coins to form the amount is: " << result << endl;
    }

    return 0;
}