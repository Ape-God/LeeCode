#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> dp(nums.size(), 1); // dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
        int max_length = 1; // 至少包含一个元素

        // 动态规划求解最长递增子序列
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_length = max(max_length, dp[i]);
        }

        return max_length;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 }; // 示例数组
    cout << "Length of Longest Increasing Subsequence: " << solution.lengthOfLIS(nums) << endl;
    return 0;
}