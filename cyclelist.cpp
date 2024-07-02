#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        // ������������ֻ��0�׻�1�ף�ֻ��һ�ַ�������¥��
        if (n == 1) return 1;
        if (n == 0) return 0;

        // ����һ���������洢����ÿһ�׵ķ�����
        std::vector<int> dp(n + 1, 0);

        // ��ʼ�������ǰ����Ԫ��
        dp[1] = 1; // ����1�׵ķ�������1
        dp[2] = 2; // ����2�׵ķ�������2��1+1 �� 2��

        // ��̬�滮���
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // ���ص���n�׵ķ�����
        return dp[n];
    }
};

int main() {
    Solution solution;
    int stairs = 5; // ������5��¥��
    std::cout << "���� " << stairs << " ��¥�ݵķ������ǣ�" << solution.climbStairs(stairs) << std::endl;
    return 0;
}