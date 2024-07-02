#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
        int rows = board.size();
        int cols = board[0].size();

        // 遍历面板每一个格子里的细胞
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int liveNeighbors = 0;
                // 对于每一个细胞统计其八个相邻位置里的活细胞数量
                for (int i = 0; i < 8; i++) {
                    int nr = row + neighbors[i][0];
                    int nc = col + neighbors[i][1];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 1) {
                        liveNeighbors++;
                    }
                }

                // 根据生命游戏的规则预处理细胞状态
                if (board[row][col] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[row][col] = -1; // 标记为将要死亡的活细胞
                }
                else if (board[row][col] == 0 && liveNeighbors == 3) {
                    board[row][col] = 2; // 标记为将要复活的死细胞
                }
            }
        }

        // 根据预处理更新细胞的最终状态
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == -1) {
                    board[row][col] = 0; // 更新为死细胞
                }
                else if (board[row][col] == 2) {
                    board[row][col] = 1; // 更新为活细胞
                }
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1, 1},
        {1, 1, 0, 0}
    };

    solution.gameOfLife(board);

    // 打印最终的面板状态
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell == 1 ? "◻" : "◼") << " "; // 打印活细胞或死细胞
        }
        cout << endl;
    }

    return 0;
}