#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(const std::vector<std::vector<char>>& board) {
        std::unordered_set<char> rows[9], cols[9], boxes[9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num != '.') {
                    int boxIndex = (i / 3) * 3 + j / 3;
                    if (rows[i].count(num) || cols[j].count(num) || boxes[boxIndex].count(num))
                        return false;
                    rows[i].insert(num);
                    cols[j].insert(num);
                    boxes[boxIndex].insert(num);
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    // Ê¾ÀýÊý¶À°å
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    bool isValid = solution.isValidSudoku(board);
    std::cout << (isValid ? "The Sudoku is valid." : "The Sudoku is not valid.") << std::endl;

    return 0;
}