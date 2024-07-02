#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 主函数，用于计算不同路径的数量
    int uniquePaths(int m, int n) {
        vector<vector<long long>> dp(m, vector<long long>(n, 1)); // 初始化动态规划数组

        // 遍历网格，更新路径数
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // 到达当前格子的路径数是左边格子和上边格子路径数的和
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // 返回到达右下角格子的路径数
        return dp[m - 1][n - 1];
    }
};

// 示例函数，用于演示 Solution 类的 uniquePaths 方法
int main() {
    Solution solution;
    // 调用 uniquePaths 方法并输出结果
    int m = 3, n = 7; // 网格的行数和列数
    cout << "Total unique paths: " << solution.uniquePaths(m, n) << endl;

    return 0;
}