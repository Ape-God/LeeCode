#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        // ���Ƶ�һ�к͵�һ�е�ֵ����Ϊ����û����߻��ϱߵĸ���
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        // �ӵڶ��еڶ��п�ʼ��ʹ�ö�̬�滮������С·����
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // ѡ����߸��Ӻ��ϱ߸��ӵ���Сֵ��Ȼ����ϵ�ǰ���ӵ�ֵ
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        // ���½ǵ�ֵ��Ϊ�������С·����
        return grid[m - 1][n - 1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int result = solution.minPathSum(grid);
    cout << "The minimum path sum is: " << result << endl;

    return 0;
}