#include <iostream>
#include <vector>
#include <algorithm> // 用于 std::max 和 std::min

using namespace std;

class Solution {
public:
    // 主函数，用于找出乘积最大的子数组
    int maxProduct(vector<int>& nums) {
        // 使用 double 类型来避免整数溢出问题
        double maxF = nums[0], minF = nums[0], ans = nums[0];

        // 从数组的第二个元素开始遍历
        for (int i = 1; i < nums.size(); ++i) {
            // 保存当前最大乘积和最小乘积的副本
            double mx = maxF, mn = minF;

            // 更新 maxF，它可能是当前最大乘积与当前元素的乘积，
            // 或者是当前元素自身（如果它比乘积后的值更大），
            // 以及当前最小乘积与当前元素的乘积（考虑负数乘法）
            maxF = max(mx * nums[i], max(static_cast<double>(nums[i]), mn * nums[i]));

            // 更新 minF，它可能是当前最小乘积与当前元素的乘积，
            // 或者是当前元素自身（如果它比乘积后的值更小），
            // 以及当前最大乘积与当前元素的乘积（考虑正数乘法）
            minF = min(mn * nums[i], min(static_cast<double>(nums[i]), mx * nums[i]));

            // 更新 ans 为 maxF 和 ans 之间的较大值
            ans = max(maxF, ans);
        }

        // 将最终结果转换为整数类型并返回
        return static_cast<int>(ans);
    }
};


// 示例函数，用于演示 Solution 类的 maxProduct 方法
int main() {
    Solution solution;
    // 创建一个示例数组
    vector<int> nums = { 2, 3, -2, 4 };
    // 调用 maxProduct 方法并输出结果
    int maxProductResult = solution.maxProduct(nums);
    cout << "Maximum product of a subarray is: " << maxProductResult << endl;

    return 0;
}