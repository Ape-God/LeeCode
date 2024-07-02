#include <iostream>
#include <vector>
#include <string>
#include<iostream>
using namespace std;

class Solution {
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int idx, int x, int y) {
        if (board[x][y] != word[idx]) {
            return false;
        }
        if (idx == word.length() - 1) {
            return true;
        }
        char temp = board[x][y];
        board[x][y] = '.'; // Mark the cell as visited
        bool found = false;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] != '.') {
                if (dfs(board, word, idx + 1, nx, ny)) {
                    found = true;
                    break;
                }
            }
        }

        board[x][y] = temp; // Unmark the cell
        return found;
    }
};

void testSolution(Solution& solution, vector<vector<char>>& board, const string& word) {
    bool result = solution.exist(board, word); // exist 不需要 const 限定，因为它可能会修改 board
    cout << (result ? "true" : "false") << endl;
}

int main() {
    Solution solution;
    vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
    string word = "ABCCED";
    testSolution(solution, board, word);
    board = { {'A','B','C','E'} };
    word = "ABCB";
    testSolution(solution, board, word);

    return 0;
}