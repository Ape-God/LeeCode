#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // �����������ڼ�����¥�ݵ���ͻ���
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); // ��ȡ¥�ݵ�̨����
        vector<int> dp(n + 1); // ��ʼ��һ������Ϊ n+1 �� dp ���飬���ڴ洢����ÿ��̨�׵���ͻ���
        // dp[0] �� dp[1] ����Ϊ 0����Ϊ��̨�� 0 �� 1 ��ʼ����Ҫ���⻨��
        dp[0] = dp[1] = 0;

        // �ӵ� 2 ��̨�׿�ʼ������ֱ�����һ��̨��
        for (int i = 2; i <= n; i++) {
            // ����ÿ��̨�� i������� i-1 �� i-2 ̨������ i ̨�׵���ͻ���
            // ѡ������֮��Ľ�Сֵ�����ϵ�ǰ̨�׵ķ��� cost[i-1]
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        // ���ص������һ��̨�׵���ͻ��ѣ�ע�ⲻ��Ҫ�������һ��̨�׵ķ���
        // ��Ϊ��ĿҪ���ǵ��ﶥ�����������뿪���һ��̨��
        return dp[n];
    }
};


class Solution {
public:
    // �����������ڼ�����¥�ݵ���ͻ���
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); // ��ȡ¥�ݵ�̨����
        // ��ʼ���������� prev �� curr �ֱ��ʾ����� i-1 ���͵� i ������ͻ���
        int prev = 0, curr = 0;

        // �ӵ� 2 ��̨�׿�ʼ������ֱ�����һ��̨��
        for (int i = 2; i <= n; i++) {
            // ���㵽��� i ��̨�׵���ͻ���
            // �����ͨ���ӵ� i-1 ��̨�׻�� i-2 ��̨�׼�����Ӧ�� cost ��ʵ��
            int next = min(curr + cost[i - 1], prev + cost[i - 2]);

            // ���� prev �� curr��prev ���ڱ�ʾ����� i ������ͻ��ѣ�curr ��ʾ����� i+1 ������ͻ���
            prev = curr;
            curr = next;
        }

        // ���ص������һ��̨�׵���ͻ���
        // ע�⣺�������ǿ��Դ����һ��̨��֮ǰ������һ��̨�׵��ﶥ��
        // ���Է��ص� curr �Ǵ����һ��̨��֮ǰ����ͻ���
        return curr;
    }
};




// ʾ��������������ʾ Solution ��� minCostClimbingStairs ����
int main() {
    Solution solution;
    // ����һ��ʾ��¥�ݷ�������
    vector<int> cost = { 10, 15, 20 };

    // ���� minCostClimbingStairs ������������
    int result = solution.minCostClimbingStairs(cost);
    cout << "Minimum cost to climb the stairs: " << result << endl;

    return 0;
}