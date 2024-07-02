#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            // ״̬ת�Ʒ��̣�dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
            // ��͵�� i �����ݣ���ô��߽����� dp[i - 1]
            // ͵�� i �����ݣ���ô��߽����� dp[i - 2] + nums[i]����Ϊ����͵ i - 1 �����ݣ�
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp.back(); // �������һ��Ԫ�أ��������������߽��
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 2, 7, 9, 3, 1 }; // ʾ�����ݽ������

    int result = solution.rob(nums);
    cout << "The maximum amount of money the thief can rob is: " << result << endl;

    return 0;
}