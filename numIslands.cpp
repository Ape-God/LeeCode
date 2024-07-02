#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//class Solution {
//public:
//    // �����ά�����е��������
//    int numIslands(vector<vector<char>>& grid) {
//        if (grid.empty()) return 0; // �������Ϊ�գ�û�е���
//
//        int islands = 0; // ���������
//        int rows = grid.size(); // ���������
//        int cols = grid[0].size(); // ���������
//
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < cols; ++j) {
//                if (grid[i][j] == '1') { // �����ǰλ����½��
//                    islands++; // ����������1
//                    bfs(grid, i, j); // ִ�й�����������������ڵ�½�ر��Ϊ�ѷ���
//                }
//            }
//        }
//
//        return islands; // ���ص��������
//    }
//
//private:
//    // ��������������������ڱ�ǵ�����Χ��½��
//    void bfs(vector<vector<char>>& grid, int x, int y) {
//        queue<pair<int, int>> q; // ʹ�ö��д洢�����ʵĽڵ�
//        q.push({ x, y }); // ����ǰ½�ؽڵ�������
//        grid[x][y] = '0'; // ����ǰ�ڵ���Ϊ�ѷ���
//
//        vector<pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // �ĸ�����
//
//        while (!q.empty()) {
//            auto [row, col] = q.front(); // ȡ�������еĽڵ�
//            q.pop();
//
//            for (auto& dir : directions) { // �����ĸ�����
//                int newRow = row + dir.first; // �µ�������
//                int newCol = col + dir.second; // �µ�������
//
//                if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == '1') {
//                    q.push({ newRow, newCol }); // �����ڵ�½�ؼ������
//                    grid[newRow][newCol] = '0'; // ���Ϊ�ѷ���
//                }
//            }
//        }
//    }
//};


class Solution {
private:
    // �������������DFS���������������ڱ�������
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size(); // ��ȡ���������
        int nc = grid[0].size(); // ��ȡ���������

        // ����ǰλ�ñ��Ϊ�ѷ��ʣ�ˮ��
        grid[r][c] = '0';

        // ��鲢�ݹ���ʱ����ϡ��������ĸ����������½�ص�Ԫ��
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c); // ����
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c); // �ϱ�
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1); // ����
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1); // ����
    }

public:
    // ���������е��������
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size(); // ���������
        if (!nr) return 0; // �������Ϊ�գ���������Ϊ0

        int nc = grid[0].size(); // ���������
        int num_islands = 0; // ���������

        // ���������ÿ����Ԫ��
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                // �����ǰ��Ԫ���ǵ����һ���֣�ֵΪ'1'��
                if (grid[r][c] == '1') {
                    // �������������1
                    ++num_islands;
                    // ����DFS�����������ӵ�ǰ��Ԫ��ʼ������������
                    dfs(grid, r, c);
                }
            }
        }

        // ���ؼ�����ĵ�������
        return num_islands;
    }
};


// ʾ������
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