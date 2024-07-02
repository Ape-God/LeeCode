#include <iostream>
#include <vector>

using namespace std;


class Solution {
    const long long mod = 1e9 + 7; // 定义模数，用于取模操作
public:
    // 主函数，用于计算平铺 2 x n 面板的方法数量
    int numTilings(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(4, 0)); // 初始化动态规划数组
        dp[0][3] = 1; // 基础情况，平铺 2 x 0 面板有一种方法

        // 遍历从 1 到 n
        for (int i = 1; i <= n; i++) {
            // dp[i][0] 表示以多米诺开始平铺的方式数，与 dp[i - 1][3] 相同
            dp[i][0] = dp[i - 1][3];
            // dp[i][1] 表示以水平托米诺开始平铺的方式数，可以由前一个面板的第 0 或第 2 种方式转换而来
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            // dp[i][2] 表示以垂直托米诺开始平铺的方式数，可以由前一个面板的第 0 或第 1 种方式转换而来
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            // dp[i][3] 表示平铺第 i 行面板的总方式数，是前面所有情况的和
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        // 返回平铺第 n 行面板的总方式数
        return dp[n][3];
    }
};

// 示例函数，用于演示 Solution 类的 numTilings 方法
int main() {
    Solution solution;
    // 调用 numTilings 方法并输出结果
    for (int i = 1; i <= 10; ++i) { // 测试前10个数
        cout << "The number of tilings for a 2x" << i << " panel is: " << solution.numTilings(i) << endl;
    }

    return 0;
}