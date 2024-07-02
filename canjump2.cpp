#include <vector>
#include <iostream>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0; // 如果数组只有一个元素，不需要跳跃

        int end = 0; // end 表示当前可以到达的最远位置
        int farthest = 0; // farthest 表示下一次跳跃可以到达的最远位置
        int steps = 0; // 记录跳跃的次数

        for (int i = 0; i < n - 1; ++i) {
            // 更新下一次可以跳跃到达的最远位置
            farthest = std::max(farthest, i + nums[i]);
            if (i == end) {
                // 如果当前位置是之前跳跃的最远位置，更新end，并增加steps
                end = farthest;
                steps++;
            }
        }
        return steps; // 返回总的跳跃次数
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 2, 3, 1, 1, 4 };
    int minSteps = solution.jump(nums);
    std::cout << "Minimum steps to jump to the end: " << minSteps << std::endl;
    return 0;
}