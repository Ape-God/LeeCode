#include <vector>
#include <iostream>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0; // �������ֻ��һ��Ԫ�أ�����Ҫ��Ծ

        int end = 0; // end ��ʾ��ǰ���Ե������Զλ��
        int farthest = 0; // farthest ��ʾ��һ����Ծ���Ե������Զλ��
        int steps = 0; // ��¼��Ծ�Ĵ���

        for (int i = 0; i < n - 1; ++i) {
            // ������һ�ο�����Ծ�������Զλ��
            farthest = std::max(farthest, i + nums[i]);
            if (i == end) {
                // �����ǰλ����֮ǰ��Ծ����Զλ�ã�����end��������steps
                end = farthest;
                steps++;
            }
        }
        return steps; // �����ܵ���Ծ����
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 2, 3, 1, 1, 4 };
    int minSteps = solution.jump(nums);
    std::cout << "Minimum steps to jump to the end: " << minSteps << std::endl;
    return 0;
}