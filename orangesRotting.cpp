#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    // 计算直到没有新鲜橘子为止所必须经过的最小分钟数
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        // 存储腐烂橘子的队列和新鲜橘子的总数
        queue<pair<int, int>> rotten;
        int freshCount = 0;

        // 寻找腐烂的橘子和统计新鲜橘子的数量
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    rotten.push({ i, j });
                }
                else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // 如果没有新鲜橘子，直接返回0
        if (freshCount == 0) return 0;

        int minutes = 0; // 腐烂所需的分钟数
        while (!rotten.empty() && freshCount > 0) {
            int size = rotten.size();
            minutes++; // 每分钟检查所有腐烂的橘子
            for (int k = 0; k < size; ++k) {
                auto [r, c] = rotten.front();
                rotten.pop();
                // 检查四个方向的新鲜橘子并使其腐烂
                for (auto& [dr, dc] : directions) {
                    int newR = r + dr, newC = c + dc;
                    if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == 1) {
                        grid[newR][newC] = 2; // 橘子腐烂
                        freshCount--; // 新鲜橘子数量减少
                        rotten.push({ newR, newC }); // 将新的腐烂橘子加入队列
                    }
                }
            }
        }

        // 如果没有新鲜橘子了，返回分钟数，否则返回-1
        return freshCount > 0 ? -1 : minutes;
    }

private:
    // 定义4个方向的偏移量
    vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
};

// 示例调用
int main() {
    Solution solution;
    vector<vector<int>> grid1 = { {2,1,1},{1,1,0},{0,1,1} };
    cout << "Output: " << solution.orangesRotting(grid1) << endl;

    vector<vector<int>> grid2 = { {2,1,1},{0,1,1},{1,0,1} };
    cout << "Output: " << solution.orangesRotting(grid2) << endl;

    vector<vector<int>> grid3 = { {0,2} };
    cout << "Output: " << solution.orangesRotting(grid3) << endl;

    return 0;
}