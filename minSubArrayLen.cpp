#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int minSubArrayLen(int s, std::vector<int>& nums) {
        int n = nums.size();
        int minLen = n + 1; // 初始化最小长度为一个大于数组长度的值
        int left = 0;
        int sum = 0;

        for (int right = 0; right < n; ++right) {
            sum += nums[right]; // 将右侧元素加到当前和

            while (sum >= s) {
                minLen = std::min(minLen, right - left + 1); // 更新最小长度
                sum -= nums[left]; // 移动左侧指针，减去左侧元素
                left++; // 左侧指针向右移动
            }
        }

        return minLen != n + 1 ? minLen : 0; // 如果没有找到合适的子数组，返回0
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 2, 3, 1, 2, 4, 3 };
    int s = 7;

    int result = solution.minSubArrayLen(s, nums);
    std::cout << "The length of the shortest subarray is: " << result << std::endl;

    return 0;
}