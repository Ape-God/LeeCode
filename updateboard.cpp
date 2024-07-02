#include <vector>
#include <iostream>
using namespace std;

//class Solution {
//public:
//    void dfs(vector<vector<char>>& board, int x, int y) {
//        int n = board.size();
//        int m = board[0].size();
//        // ���߽�����
//        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 'B' || board[x][y] == 'X') {
//            return;
//        }
//
//        if (board[x][y] == 'M') {
//            board[x][y] = 'X'; // �ڵ����ף���Ϸ����
//        }
//        else {
//            int count = 0; // �������ڵ�������
//            for (int i = -1; i <= 1; ++i) {
//                for (int j = -1; j <= 1; ++j) {
//                    if (i == 0 && j == 0) continue; // ������ǰλ������
//                    if (x + i >= 0 && x + i < n && y + j >= 0 && y + j < m && board[x + i][y + j] == 'M') {
//                        count++;
//                    }
//                }
//            }
//            if (count == 0) {
//                board[x][y] = 'B'; // û�����ڵ��ף���Ϊ 'B'
//                for (int i = -1; i <= 1; ++i) {
//                    for (int j = -1; j <= 1; ++j) {
//                        dfs(board, x + i, y + j); // �����ڷ�����еݹ�
//                    }
//                }
//            }
//            else {
//                board[x][y] = '0' + count; // �����ڵ��ף���Ϊ��Ӧ������
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
            // �����ж� M����Ϊ����� M �Ļ���Ϸ�Ѿ�������
            cnt += board[tx][ty] == 'M';
        }
        if (cnt > 0) {
            // ���� 3
            board[x][y] = cnt + '0';
        }
        else {
            // ���� 2
            board[x][y] = 'B';
            for (int i = 0; i < 8; ++i) {
                int tx = x + dir_x[i];
                int ty = y + dir_y[i];
                // ���ﲻ��Ҫ�ڴ��� B ��ʱ�������չ����Ϊ B ֮ǰ�������ʱ���Ѿ�����չ����
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
            // ���� 1
            board[x][y] = 'X';
        }
        else {
            dfs(board, x, y);
        }
        return board;
    }
};



// �����������ڲ���
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