#include <vector>
#include <iostream>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReach = 0; // ��Զ���Ե����λ��
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // �����ǰλ�ò��ܵ�������Ѿ��ﵽ��Զλ�ã����޷�������
            if (i > maxReach) return false;
            // ������Զ���Ե����λ��
            maxReach = std::max(maxReach, i + nums[i]);
        }
        // ����ܹ���������ĩβ���򷵻�true
        return true;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 2, 3, 1, 1, 4 };
    bool canReachEnd = solution.canJump(nums);
    if (canReachEnd) {
        std::cout << "Can jump to the end" << std::endl;
    }
    else {
        std::cout << "Cannot jump to the end" << std::endl;
    }
    return 0;
}