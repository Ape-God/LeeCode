#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // �����������ڼ��㲻ͬ·��������
    int uniquePaths(int m, int n) {
        vector<vector<long long>> dp(m, vector<long long>(n, 1)); // ��ʼ����̬�滮����

        // �������񣬸���·����
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // ���ﵱǰ���ӵ�·��������߸��Ӻ��ϱ߸���·�����ĺ�
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // ���ص������½Ǹ��ӵ�·����
        return dp[m - 1][n - 1];
    }
};

// ʾ��������������ʾ Solution ��� uniquePaths ����
int main() {
    Solution solution;
    // ���� uniquePaths ������������
    int m = 3, n = 7; // ���������������
    cout << "Total unique paths: " << solution.uniquePaths(m, n) << endl;

    return 0;
}