#include <iostream>
#include <vector>
#include <cstdlib> // 用于abs函数

using namespace std;

class Solution {
public:
    // 主函数，用于找出未出现的最小正整数
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 将所有非正数和大于n的数放到数组的末尾
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // 再次遍历数组，找到第一个不满足 nums[i] == i + 1 的位置
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1; // 返回这个位置的正整数
            }
        }

        return n + 1; // 如果数组中1到n都在，返回n+1
    }
};

// 示例函数，用于演示 Solution 类的 firstMissingPositive 方法
int main() {
    Solution solution;
    // 创建一个示例数组
    vector<int> nums = { 3, 4, -1, 1 };
    // 调用 firstMissingPositive 方法并输出结果
    int missing = solution.firstMissingPositive(nums);
    cout << "The first missing positive is: " << missing << endl;

    // 可以添加更多的测试案例
    vector<int> nums2 = { 7, 8, 9, 11, 12 };
    missing = solution.firstMissingPositive(nums2);
    cout << "The first missing positive is: " << missing << endl;

    vector<int> nums3 = { 1, 2, 0 };
    missing = solution.firstMissingPositive(nums3);
    cout << "The first missing positive is: " << missing << endl;

    return 0;
}