#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int minSubArrayLen(int s, std::vector<int>& nums) {
        int n = nums.size();
        int minLen = n + 1; // ��ʼ����С����Ϊһ���������鳤�ȵ�ֵ
        int left = 0;
        int sum = 0;

        for (int right = 0; right < n; ++right) {
            sum += nums[right]; // ���Ҳ�Ԫ�ؼӵ���ǰ��

            while (sum >= s) {
                minLen = std::min(minLen, right - left + 1); // ������С����
                sum -= nums[left]; // �ƶ����ָ�룬��ȥ���Ԫ��
                left++; // ���ָ�������ƶ�
            }
        }

        return minLen != n + 1 ? minLen : 0; // ���û���ҵ����ʵ������飬����0
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 2, 3, 1, 2, 4, 3 };
    int s = 7;

    int result = solution.minSubArrayLen(s, nums);
    std::cout << "The length of the shortest subarray is: " << result << std::endl;

    return 0;
}