#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        // 复制第一行和第一列的值，因为它们没有左边或上边的格子
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        // 从第二行第二列开始，使用动态规划计算最小路径和
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // 选择左边格子和上边格子的最小值，然后加上当前格子的值
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        // 右下角的值即为所求的最小路径和
        return grid[m - 1][n - 1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int result = solution.minPathSum(grid);
    cout << "The minimum path sum is: " << result << endl;

    return 0;
}