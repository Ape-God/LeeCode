#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 主函数，用于计算和为n的完全平方数的最少数量
    int numSquares(int n) {
        // 使用动态规划来存储中间结果
        vector<int> dp(n + 1, 0);
        dp[0] = 0; // 如果数为0，不需要任何平方数

        // 从1开始到n，计算每个数的完全平方数和的最少数量
        for (int i = 1; i <= n; ++i) {
            // 初始化当前dp值为一个较大的数，比如n+1
            dp[i] = n + 1;

            // 从1到i，检查每个数j，如果i - j的平方小于或等于i，尝试更新dp[i]
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        // 返回dp[n]，即和为n的完全平方数的最少数量
        return dp[n];
    }
};

// 示例函数，用于演示 Solution 类的 numSquares 方法
int main() {
    Solution solution;
    // 调用 numSquares 方法并输出结果
    int n = 12;
    cout << "The minimum number of squares that sum up to " << n << " is: "
        << solution.numSquares(n) << endl;

    return 0;
}