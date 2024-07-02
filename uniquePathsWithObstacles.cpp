#include <vector>
#include <iostream>
using namespace std;

//class Solution {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        int m = obstacleGrid.size();
//        if (m == 0 || obstacleGrid[0][0] == 1) return 0; // 初始位置有障碍物
//        int n = obstacleGrid[0].size();
//
//        vector<vector<int>> dp(m, vector<int>(n, 0));
//
//        // 如果起点有障碍物，则无路径
//        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
//
//        // 初始化第一行
//        for (int j = 1; j < n; ++j) {
//            dp[0][j] = obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1 ? 1 : 0;
//        }
//
//        // 初始化第一列
//        for (int i = 1; i < m; ++i) {
//            dp[i][0] = obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1 ? 1 : 0;
//        }
//
//        // 动态规划填充dp表
//        for (int i = 1; i < m; ++i) {
//            for (int j = 1; j < n; ++j) {
//                // 如果当前位置没有障碍物，则路径数为左边和上边格子的路径数之和
//                if (obstacleGrid[i][j] == 0) {
//                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//                }
//            }
//        }
//
//        return dp[m - 1][n - 1];
//    }
//};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector <int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    f[j] += f[j - 1];
                }
            }
        }

        return f.back();
    }
};




int main() {
    Solution solution;
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int result = solution.uniquePathsWithObstacles(obstacleGrid);
    cout << "The number of unique paths is: " << result << endl;

    return 0;
}