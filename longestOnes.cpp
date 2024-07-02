#include <vector>
#include <iostream>
#include <deque>
using namespace std;

class Solution {
public:
    // 主函数，用于找出数组中长度为 k 的子数组中1的最大连续出现次数
    int longestOnes(vector<int>& nums, int k) {
        int maxCount = 0; // 初始化最长连续1的个数为0
        deque<int> zeroIndices; // 使用双端队列存储0的索引

        int left = 0; // 初始化左边界
        for (int right = 0; right < nums.size(); ++right) {
            // 如果当前元素是0，记录其索引
            if (nums[right] == 0) {
                zeroIndices.push_back(right);
            }

            // 当队列中的0的个数超过k，需要移动左边界
            while (zeroIndices.size() > k) {
                // 移动左边界到下一个1的右侧
                left = zeroIndices.front() + 1;
                // 移除窗口左侧的0，因为它们已经被计算过
                zeroIndices.pop_front();
            }

            // 更新最长连续1的个数，计算当前窗口的长度
            maxCount = max(maxCount, right - left + 1);
        }

        // 返回最长连续1的个数
        return maxCount;
    }
};

class Solution {
public:
    // 主函数，用于找出包含最多 k 个 0 的子数组的长度
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, cnt = 0, n = nums.size(), res = 0;
        // l 和 r 是左右指针，cnt 是窗口中 0 的数量，n 是数组长度，res 是结果
        while (r < n) {
            // 如果右指针所指的元素是 0，计数器加一
            if (nums[r++] == 0) {
                cnt++;
            }
            // 当窗口中 0 的数量超过 k 时，移动左指针
            // 直到窗口中 0 的数量不超过 k
            while (cnt > k) {
                if (nums[l++] == 0) {
                    cnt--; // 如果左指针所指的元素是 0，计数器减一
                }
            }
            // 更新结果 res，为左右指针之间的距离
            res = max(res, r - l);
        }
        return res; // 返回最长子数组的长度
    }
};




// 测试函数
void testSolution(Solution& solution, vector<int>& nums, int k) {
    int result = solution.longestOnes(nums, k);
    cout << "The length of the longest ones is: " << result << endl;
}

int main() {
    Solution solution;
    vector<int> nums1 = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
    int k1 = 2;
    testSolution(solution, nums1, k1);

    vector<int> nums2 = { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 };
    int k2 = 3;
    testSolution(solution, nums2, k2);

    return 0;
}