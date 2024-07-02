#include <vector>
#include <algorithm> // 引入algorithm库，用于max函数
#include <iostream>

using namespace std;

class Solution {
public:
    // 找到给定数组中子数组的最大和
    int maxSubArray(vector<int>& nums) {
        // 如果数组为空，返回0
        if (nums.empty()) return 0;

        // 初始化max_so_far和current_max为数组的第一个元素
        int max_so_far = nums[0];
        int current_max = nums[0];

        // 从数组的第二个元素开始遍历
        for (int i = 1; i < nums.size(); ++i) {
            // current_max更新为当前元素和current_max加上当前元素的最大值
            // 这相当于在每个位置决定是开始一个新的子数组还是继续当前子数组
            current_max = max(nums[i], current_max + nums[i]);

            // 更新max_so_far为目前为止找到的最大子数组和
            max_so_far = max(max_so_far, current_max);
        }

        // 返回最大子数组的和
        return max_so_far;
    }
};

// 主函数，用于测试Solution类的maxSubArray成员函数
int main() {
    // 创建Solution对象
    Solution solution;

    // 创建一个整数数组
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };

    // 调用maxSubArray函数，找出数组中的最大子数组和
    int maxSum = solution.maxSubArray(nums);

    // 打印结果
    cout << "Maximum sum of a subarray is: " << maxSum << endl;

    return 0;
}