#include <vector>
#include <iostream>
using namespace std;

//class Solution {
//public:
//    void dfs(vector<vector<char>>& board, int x, int y) {
//        int n = board.size();
//        int m = board[0].size();
//        // 检查边界条件
//        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 'B' || board[x][y] == 'X') {
//            return;
//        }
//
//        if (board[x][y] == 'M') {
//            board[x][y] = 'X'; // 挖到地雷，游戏结束
//        }
//        else {
//            int count = 0; // 计算相邻地雷数量
//            for (int i = -1; i <= 1; ++i) {
//                for (int j = -1; j <= 1; ++j) {
//                    if (i == 0 && j == 0) continue; // 跳过当前位置自身
//                    if (x + i >= 0 && x + i < n && y + j >= 0 && y + j < m && board[x + i][y + j] == 'M') {
//                        count++;
//                    }
//                }
//            }
//            if (count == 0) {
//                board[x][y] = 'B'; // 没有相邻地雷，改为 'B'
//                for (int i = -1; i <= 1; ++i) {
//                    for (int j = -1; j <= 1; ++j) {
//                        dfs(board, x + i, y + j); // 对相邻方块进行递归
//                    }
//                }
//            }
//            else {
//                board[x][y] = '0' + count; // 有相邻地雷，改为相应的数字
//            }
//        }
//    }
//
//    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
//        int clickr = click[0];
//        int clickc = click[1];
//        if (board[clickr][clickc] == 'M') {
//            board[clickr][clickc] = 'X';
//        }
//        else {
//            dfs(board, clickr, clickc);
//        }
//        return board;
//    }
//};

class Solution {
public:
    int dir_x[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
    int dir_y[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };

    void dfs(vector<vector<char>>& board, int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 8; ++i) {
            int tx = x + dir_x[i];
            int ty = y + dir_y[i];
            if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()) {
                continue;
            }
            // 不用判断 M，因为如果有 M 的话游戏已经结束了
            cnt += board[tx][ty] == 'M';
        }
        if (cnt > 0) {
            // 规则 3
            board[x][y] = cnt + '0';
        }
        else {
            // 规则 2
            board[x][y] = 'B';
            for (int i = 0; i < 8; ++i) {
                int tx = x + dir_x[i];
                int ty = y + dir_y[i];
                // 这里不需要在存在 B 的时候继续扩展，因为 B 之前被点击的时候已经被扩展过了
                if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E') {
                    continue;
                }
                dfs(board, tx, ty);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            // 规则 1
            board[x][y] = 'X';
        }
        else {
            dfs(board, x, y);
        }
        return board;
    }
};



// 主函数，用于测试
int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'M', 'E'}
    };
    vector<int> click = { 3, 0 };
    vector<vector<char>> updatedBoard = solution.updateBoard(board, click);

    for (const auto& row : updatedBoard) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}