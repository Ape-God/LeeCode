#include <iostream>
#include <vector>
#include <algorithm> // ���� std::max �� std::min

using namespace std;

class Solution {
public:
    // �������������ҳ��˻�����������
    int maxProduct(vector<int>& nums) {
        // ʹ�� double ���������������������
        double maxF = nums[0], minF = nums[0], ans = nums[0];

        // ������ĵڶ���Ԫ�ؿ�ʼ����
        for (int i = 1; i < nums.size(); ++i) {
            // ���浱ǰ���˻�����С�˻��ĸ���
            double mx = maxF, mn = minF;

            // ���� maxF���������ǵ�ǰ���˻��뵱ǰԪ�صĳ˻���
            // �����ǵ�ǰԪ������������ȳ˻����ֵ���󣩣�
            // �Լ���ǰ��С�˻��뵱ǰԪ�صĳ˻������Ǹ����˷���
            maxF = max(mx * nums[i], max(static_cast<double>(nums[i]), mn * nums[i]));

            // ���� minF���������ǵ�ǰ��С�˻��뵱ǰԪ�صĳ˻���
            // �����ǵ�ǰԪ������������ȳ˻����ֵ��С����
            // �Լ���ǰ���˻��뵱ǰԪ�صĳ˻������������˷���
            minF = min(mn * nums[i], min(static_cast<double>(nums[i]), mx * nums[i]));

            // ���� ans Ϊ maxF �� ans ֮��Ľϴ�ֵ
            ans = max(maxF, ans);
        }

        // �����ս��ת��Ϊ�������Ͳ�����
        return static_cast<int>(ans);
    }
};


// ʾ��������������ʾ Solution ��� maxProduct ����
int main() {
    Solution solution;
    // ����һ��ʾ������
    vector<int> nums = { 2, 3, -2, 4 };
    // ���� maxProduct ������������
    int maxProductResult = solution.maxProduct(nums);
    cout << "Maximum product of a subarray is: " << maxProductResult << endl;

    return 0;
}