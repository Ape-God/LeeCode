#include <iostream>
#include <vector>

using namespace std;


class Solution {
    const long long mod = 1e9 + 7; // ����ģ��������ȡģ����
public:
    // �����������ڼ���ƽ�� 2 x n ���ķ�������
    int numTilings(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(4, 0)); // ��ʼ����̬�滮����
        dp[0][3] = 1; // ���������ƽ�� 2 x 0 �����һ�ַ���

        // ������ 1 �� n
        for (int i = 1; i <= n; i++) {
            // dp[i][0] ��ʾ�Զ���ŵ��ʼƽ�̵ķ�ʽ������ dp[i - 1][3] ��ͬ
            dp[i][0] = dp[i - 1][3];
            // dp[i][1] ��ʾ��ˮƽ����ŵ��ʼƽ�̵ķ�ʽ����������ǰһ�����ĵ� 0 ��� 2 �ַ�ʽת������
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            // dp[i][2] ��ʾ�Դ�ֱ����ŵ��ʼƽ�̵ķ�ʽ����������ǰһ�����ĵ� 0 ��� 1 �ַ�ʽת������
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            // dp[i][3] ��ʾƽ�̵� i �������ܷ�ʽ������ǰ����������ĺ�
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        // ����ƽ�̵� n �������ܷ�ʽ��
        return dp[n][3];
    }
};

// ʾ��������������ʾ Solution ��� numTilings ����
int main() {
    Solution solution;
    // ���� numTilings ������������
    for (int i = 1; i <= 10; ++i) { // ����ǰ10����
        cout << "The number of tilings for a 2x" << i << " panel is: " << solution.numTilings(i) << endl;
    }

    return 0;
}