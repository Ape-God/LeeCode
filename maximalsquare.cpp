#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int maxSide = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // 第一列或第一行的初始化
                    }
                    else {
                        // 从左上角的DP值减去1，然后与左边和上边的DP值中较小者取最小
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]); // 更新最大边长
                }
            }
        }

        return maxSide * maxSide; // 返回最大正方形的面积
    }
};

int main() {
    Solution solution;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '1', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int area = solution.maximalSquare(matrix);
    cout << "The area of the maximal square is: " << area << endl;

    return 0;
}