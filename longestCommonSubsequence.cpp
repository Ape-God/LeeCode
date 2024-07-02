#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 主函数，用于计算最长公共子序列的长度
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length(); // 获取两个字符串的长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // 初始化动态规划数组

        // 从1开始遍历text1，dp[i][j]表示text1的前i个字符和text2的前j个字符的最长公共子序列的长度
        for (int i = 1; i <= m; i++) {
            char c1 = text1.at(i - 1); // 获取text1的第i个字符
            // 从1开始遍历text2
            for (int j = 1; j <= n; j++) {
                char c2 = text2.at(j - 1); // 获取text2的第j个字符

                // 如果当前字符相等，那么最长公共子序列长度加1
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                // 如果当前字符不等，取左边或上边格子的较大值
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // 返回dp[m][n，即两个字符串的最长公共子序列的长度
        return dp[m][n];
    }
};

// 示例函数，用于演示 Solution 类的 longestCommonSubsequence 方法
int main() {
    Solution solution;
    // 调用 longestCommonSubsequence 方法并输出结果
    string text1 = "abcde";
    string text2 = "ace";
    cout << "Length of longest common subsequence: " << solution.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}