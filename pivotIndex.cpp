#include <vector>
#include <numeric> // 用于accumulate函数
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // 寻找数组的中心下标
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0); // 计算数组所有元素的总和
        int leftSum = 0; // 初始化左侧元素的和为0

        // 遍历数组
        for (size_t i = 0; i < nums.size(); ++i) {
            // 如果左侧的和等于右侧的和（总和减去当前元素和左侧的和）
            if (leftSum == (totalSum - nums[i] - leftSum)) {
                return i; // 返回当前索引作为中心下标
            }
            // 更新左侧的和
            leftSum += nums[i];
        }

        // 如果没有找到中心下标，返回-1
        return -1;
    }
};

// 示例调用
int main() {
    Solution solution;
    vector<int> nums = { 1, 7, 3, 6, 5, 6 }; // 示例输入

    int pivot = solution.pivotIndex(nums); // 调用函数寻找中心下标
    cout << "The pivot index is: " << (pivot != -1 ? to_string(pivot) : "None") << endl; // 输出中心下标

    return 0;
}