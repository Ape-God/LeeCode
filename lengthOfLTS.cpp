#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> dp(nums.size(), 1); // dp[i] ��ʾ�� nums[i] ��β������������еĳ���
        int max_length = 1; // ���ٰ���һ��Ԫ��

        // ��̬�滮��������������
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_length = max(max_length, dp[i]);
        }

        return max_length;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 }; // ʾ������
    cout << "Length of Longest Increasing Subsequence: " << solution.lengthOfLIS(nums) << endl;
    return 0;
}