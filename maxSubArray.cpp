#include <vector>
#include <algorithm> // ����algorithm�⣬����max����
#include <iostream>

using namespace std;

class Solution {
public:
    // �ҵ����������������������
    int maxSubArray(vector<int>& nums) {
        // �������Ϊ�գ�����0
        if (nums.empty()) return 0;

        // ��ʼ��max_so_far��current_maxΪ����ĵ�һ��Ԫ��
        int max_so_far = nums[0];
        int current_max = nums[0];

        // ������ĵڶ���Ԫ�ؿ�ʼ����
        for (int i = 1; i < nums.size(); ++i) {
            // current_max����Ϊ��ǰԪ�غ�current_max���ϵ�ǰԪ�ص����ֵ
            // ���൱����ÿ��λ�þ����ǿ�ʼһ���µ������黹�Ǽ�����ǰ������
            current_max = max(nums[i], current_max + nums[i]);

            // ����max_so_farΪĿǰΪֹ�ҵ�������������
            max_so_far = max(max_so_far, current_max);
        }

        // �������������ĺ�
        return max_so_far;
    }
};

// �����������ڲ���Solution���maxSubArray��Ա����
int main() {
    // ����Solution����
    Solution solution;

    // ����һ����������
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };

    // ����maxSubArray�������ҳ������е�����������
    int maxSum = solution.maxSubArray(nums);

    // ��ӡ���
    cout << "Maximum sum of a subarray is: " << maxSum << endl;

    return 0;
}