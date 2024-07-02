#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        // 基本情况：如果只有0阶或1阶，只有一种方法爬到楼顶
        if (n == 1) return 1;
        if (n == 0) return 0;

        // 创建一个数组来存储到达每一阶的方法数
        std::vector<int> dp(n + 1, 0);

        // 初始化数组的前两个元素
        dp[1] = 1; // 到达1阶的方法数是1
        dp[2] = 2; // 到达2阶的方法数是2（1+1 或 2）

        // 动态规划填表
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // 返回到达n阶的方法数
        return dp[n];
    }
};

int main() {
    Solution solution;
    int stairs = 5; // 假设有5阶楼梯
    std::cout << "爬到 " << stairs << " 阶楼梯的方法数是：" << solution.climbStairs(stairs) << std::endl;
    return 0;
}