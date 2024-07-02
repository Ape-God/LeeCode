#include <vector>
#include <iostream>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReach = 0; // 最远可以到达的位置
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // 如果当前位置不能到达，或者已经达到最远位置，则无法继续跳
            if (i > maxReach) return false;
            // 更新最远可以到达的位置
            maxReach = std::max(maxReach, i + nums[i]);
        }
        // 如果能够到达数组末尾，则返回true
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