#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 主函数，用于计算爬楼梯的最低花费
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); // 获取楼梯的台阶数
        vector<int> dp(n + 1); // 初始化一个长度为 n+1 的 dp 数组，用于存储到达每个台阶的最低花费
        // dp[0] 和 dp[1] 都设为 0，因为从台阶 0 或 1 开始不需要额外花费
        dp[0] = dp[1] = 0;

        // 从第 2 个台阶开始遍历，直到最后一个台阶
        for (int i = 2; i <= n; i++) {
            // 对于每个台阶 i，计算从 i-1 或 i-2 台阶来到 i 台阶的最低花费
            // 选择两者之间的较小值，加上当前台阶的费用 cost[i-1]
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        // 返回到达最后一个台阶的最低花费，注意不需要加上最后一个台阶的费用
        // 因为题目要求是到达顶部，而不是离开最后一个台阶
        return dp[n];
    }
};


class Solution {
public:
    // 主函数，用于计算爬楼梯的最低花费
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); // 获取楼梯的台阶数
        // 初始化两个变量 prev 和 curr 分别表示到达第 i-1 步和第 i 步的最低花费
        int prev = 0, curr = 0;

        // 从第 2 个台阶开始遍历，直到最后一个台阶
        for (int i = 2; i <= n; i++) {
            // 计算到达第 i 个台阶的最低花费
            // 这可以通过从第 i-1 个台阶或第 i-2 个台阶加上相应的 cost 来实现
            int next = min(curr + cost[i - 1], prev + cost[i - 2]);

            // 更新 prev 和 curr，prev 现在表示到达第 i 步的最低花费，curr 表示到达第 i+1 步的最低花费
            prev = curr;
            curr = next;
        }

        // 返回到达最后一个台阶的最低花费
        // 注意：由于我们可以从最后一个台阶之前的任意一个台阶到达顶部
        // 所以返回的 curr 是从最后一个台阶之前的最低花费
        return curr;
    }
};




// 示例函数，用于演示 Solution 类的 minCostClimbingStairs 方法
int main() {
    Solution solution;
    // 创建一个示例楼梯费用数组
    vector<int> cost = { 10, 15, 20 };

    // 调用 minCostClimbingStairs 方法并输出结果
    int result = solution.minCostClimbingStairs(cost);
    cout << "Minimum cost to climb the stairs: " << result << endl;

    return 0;
}