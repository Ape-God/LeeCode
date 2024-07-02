#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int count = 0, sum = 0;
//        unordered_map<int, int> um;
//        um[0] = 1; // 基础情况，前缀和为0出现1次
//
//        for (int i = 0; i < nums.size(); ++i) {
//            sum += nums[i]; // 计算前缀和
//            count += um[sum - k]; // 检查和为k的子数组数量
//            um[sum]++; // 更新前缀和sum出现的次数
//        }
//
//        return count;
//    }
//};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); ++start) {
            int sum = 0;
            for (int end = start; end >= 0; --end) {
                sum += nums[end];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};



// 测试函数
void testSolution(Solution& solution, vector<int>& nums, int k) {
    int result = solution.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << " = " << result << endl;
}

int main() {
    Solution solution;
    vector<int> nums = { 1, 1, 1 }; // 测试用例
    int k = 2; // 目标和

    testSolution(solution, nums, k);

    // 可以添加更多的测试用例
    return 0;
}