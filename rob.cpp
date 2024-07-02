#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            // 状态转移方程：dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
            // 不偷第 i 个房屋，那么最高金额就是 dp[i - 1]
            // 偷第 i 个房屋，那么最高金额就是 dp[i - 2] + nums[i]（因为不能偷 i - 1 个房屋）
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp.back(); // 返回最后一个元素，即整个数组的最高金额
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 2, 7, 9, 3, 1 }; // 示例房屋金额数组

    int result = solution.rob(nums);
    cout << "The maximum amount of money the thief can rob is: " << result << endl;

    return 0;
}