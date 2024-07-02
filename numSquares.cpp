#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // �����������ڼ����Ϊn����ȫƽ��������������
    int numSquares(int n) {
        // ʹ�ö�̬�滮���洢�м���
        vector<int> dp(n + 1, 0);
        dp[0] = 0; // �����Ϊ0������Ҫ�κ�ƽ����

        // ��1��ʼ��n������ÿ��������ȫƽ�����͵���������
        for (int i = 1; i <= n; ++i) {
            // ��ʼ����ǰdpֵΪһ���ϴ����������n+1
            dp[i] = n + 1;

            // ��1��i�����ÿ����j�����i - j��ƽ��С�ڻ����i�����Ը���dp[i]
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        // ����dp[n]������Ϊn����ȫƽ��������������
        return dp[n];
    }
};

// ʾ��������������ʾ Solution ��� numSquares ����
int main() {
    Solution solution;
    // ���� numSquares ������������
    int n = 12;
    cout << "The minimum number of squares that sum up to " << n << " is: "
        << solution.numSquares(n) << endl;

    return 0;
}