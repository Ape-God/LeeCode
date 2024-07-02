#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));

        // 初始化 dp 表的第一行和第一列
        for (int i = 0; i <= len1; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= len2; ++j) {
            dp[0][j] = j;
        }

        // 填充 dp 表
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    // 如果当前字符相同，则无需操作
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    // 如果当前字符不同，考虑所有可能的操作
                    dp[i][j] = std::min({
                        dp[i - 1][j] + 1,    // 删除操作
                        dp[i][j - 1] + 1,    // 插入操作
                        dp[i - 1][j - 1] + 1 // 替换操作
                        });
                }
            }
        }

        // 返回将 word1 转换成 word2 所需的最少操作数
        return dp[len1][len2];
    }
};

int main() {
    Solution solution;
    std::string word1 = "intention";
    std::string word2 = "execution";

    int distance = solution.minDistance(word1, word2);
    std::cout << "The minimum edit distance between \"" << word1 << "\" and \"" << word2 << "\" is: " << distance << std::endl;

    return 0;
}