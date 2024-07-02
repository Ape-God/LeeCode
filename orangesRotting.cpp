#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    // ����ֱ��û����������Ϊֹ�����뾭������С������
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        // �洢�������ӵĶ��к��������ӵ�����
        queue<pair<int, int>> rotten;
        int freshCount = 0;

        // Ѱ�Ҹ��õ����Ӻ�ͳ���������ӵ�����
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

        // ���û���������ӣ�ֱ�ӷ���0
        if (freshCount == 0) return 0;

        int minutes = 0; // ��������ķ�����
        while (!rotten.empty() && freshCount > 0) {
            int size = rotten.size();
            minutes++; // ÿ���Ӽ�����и��õ�����
            for (int k = 0; k < size; ++k) {
                auto [r, c] = rotten.front();
                rotten.pop();
                // ����ĸ�������������Ӳ�ʹ�丯��
                for (auto& [dr, dc] : directions) {
                    int newR = r + dr, newC = c + dc;
                    if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == 1) {
                        grid[newR][newC] = 2; // ���Ӹ���
                        freshCount--; // ����������������
                        rotten.push({ newR, newC }); // ���µĸ������Ӽ������
                    }
                }
            }
        }

        // ���û�����������ˣ����ط����������򷵻�-1
        return freshCount > 0 ? -1 : minutes;
    }

private:
    // ����4�������ƫ����
    vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
};

// ʾ������
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