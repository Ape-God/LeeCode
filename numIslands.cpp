#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//class Solution {
//public:
//    // 计算二维网格中岛屿的数量
//    int numIslands(vector<vector<char>>& grid) {
//        if (grid.empty()) return 0; // 如果网格为空，没有岛屿
//
//        int islands = 0; // 岛屿计数器
//        int rows = grid.size(); // 网格的行数
//        int cols = grid[0].size(); // 网格的列数
//
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < cols; ++j) {
//                if (grid[i][j] == '1') { // 如果当前位置是陆地
//                    islands++; // 岛屿数量加1
//                    bfs(grid, i, j); // 执行广度优先搜索，将相邻的陆地标记为已访问
//                }
//            }
//        }
//
//        return islands; // 返回岛屿的数量
//    }
//
//private:
//    // 广度优先搜索函数，用于标记岛屿周围的陆地
//    void bfs(vector<vector<char>>& grid, int x, int y) {
//        queue<pair<int, int>> q; // 使用队列存储待访问的节点
//        q.push({ x, y }); // 将当前陆地节点加入队列
//        grid[x][y] = '0'; // 将当前节点标记为已访问
//
//        vector<pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 四个方向
//
//        while (!q.empty()) {
//            auto [row, col] = q.front(); // 取出队列中的节点
//            q.pop();
//
//            for (auto& dir : directions) { // 遍历四个方向
//                int newRow = row + dir.first; // 新的行坐标
//                int newCol = col + dir.second; // 新的列坐标
//
//                if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == '1') {
//                    q.push({ newRow, newCol }); // 将相邻的陆地加入队列
//                    grid[newRow][newCol] = '0'; // 标记为已访问
//                }
//            }
//        }
//    }
//};


class Solution {
private:
    // 深度优先搜索（DFS）辅助函数，用于遍历岛屿
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size(); // 获取网格的行数
        int nc = grid[0].size(); // 获取网格的列数

        // 将当前位置标记为已访问（水）
        grid[r][c] = '0';

        // 检查并递归访问北、南、西、东四个方向的相邻陆地单元格
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c); // 北边
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c); // 南边
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1); // 西边
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1); // 东边
    }

public:
    // 计算网格中岛屿的总数
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size(); // 网格的行数
        if (!nr) return 0; // 如果网格为空，岛屿数量为0

        int nc = grid[0].size(); // 网格的列数
        int num_islands = 0; // 岛屿计数器

        // 遍历网格的每个单元格
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                // 如果当前单元格是岛屿的一部分（值为'1'）
                if (grid[r][c] == '1') {
                    // 岛屿计数器增加1
                    ++num_islands;
                    // 调用DFS辅助函数，从当前单元格开始遍历整个岛屿
                    dfs(grid, r, c);
                }
            }
        }

        // 返回计算出的岛屿数量
        return num_islands;
    }
};


// 示例调用
int main() {
    Solution solution;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '1', '0'},
        {'0', '0', '1', '1', '1'},
        {'0', '0', '0', '1', '1'}
    };

    int islandsCount = solution.numIslands(grid);
    cout << "Number of islands: " << islandsCount << endl;

    return 0;
}