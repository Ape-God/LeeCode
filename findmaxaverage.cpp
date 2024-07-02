#include <vector>
#include <iostream>
#include <numeric> // 用于 accumulate
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    double findMaxAverage(vector<int>& nums, int k) {
//        double maxAverage = accumulate(nums.begin(), nums.begin() + k, 0.0) / k; // 计算第一个子数组的平均数
//        double windowSum = maxAverage * k; // 当前窗口的和
//
//        // 从第二个长度为 k 的子数组开始遍历
//        for (int i = k; i < nums.size(); ++i) {
//            // 更新窗口和：减去当前窗口左侧的元素，加上新进入窗口的元素
//            windowSum += nums[i] - nums[i - k];
//            // 更新最大平均数
//            maxAverage = max(maxAverage, windowSum / k);
//        }
//
//        return maxAverage;
//    }
//};

class Solution {
public:
    // 主函数，用于找出给定窗口大小 k 的滑动窗口中的最大平均值
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0; // 初始化窗口的和为0
        int n = nums.size(); // 获取数组 nums 的大小
        // 计算窗口的初始和
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxSum = sum; // 初始化最大和为初始窗口的和

        // 遍历数组，窗口大小为 k，找出最大窗口和
        for (int i = k; i < n; ++i) {
            // 滑动窗口，减去窗口左侧的元素，加上窗口右侧的元素
            sum = sum - nums[i - k] + nums[i];
            // 更新最大窗口和
            maxSum = max(maxSum, sum);
        }

        // 将最大窗口和转换为平均值并返回，窗口大小为 k
        return static_cast<double>(maxSum) / k;
    }
};


// 测试函数
void testSolution(Solution& solution,vector<int>& nums, int k) {
    double result = solution.findMaxAverage(nums, k);
    cout << "Max average of a " << k << "-element subarray is: " << result << endl;
}

int main() {
    Solution solution;
    vector<int> nums1 = { 1, 12, 15, 8, 7, 9, 12 };
    int k1 = 3;
    testSolution(solution, nums1, k1);

    vector<int> nums2 = { 4, 3, 1 };
    int k2 = 2;
    testSolution(solution, nums2, k2);

    return 0;
}