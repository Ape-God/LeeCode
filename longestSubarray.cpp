#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    // 主函数，用于计算最长全1子数组的长度
//    int longestSubarray(vector<int>& nums) {
//        int maxLength = 0; // 初始化最长子数组长度
//        int currentLength = 0; // 当前子数组长度
//        int zeroCount = 0; // 遇到的0的数量
//
//        for (int num : nums) {
//            // 如果当前数字是1，增加当前子数组长度
//            if (num == 1) {
//                currentLength++;
//            }
//            else {
//                // 如果当前数字是0，重置当前子数组长度为1
//                // 并增加遇到的0的数量
//                maxLength = max(maxLength, currentLength);
//                currentLength = 1;
//                zeroCount++;
//            }
//        }
//        // 最后，检查是否需要更新最长长度（如果数组末尾没有0）
//        maxLength = max(maxLength, currentLength);
//
//        // 如果遇到了至少一个0，返回最长长度 - 1
//        // 因为需要删除一个元素
//        if (zeroCount > 0) {
//            return maxLength - 1;
//        }
//        // 如果没有遇到0，返回最长长度
//        return maxLength;
//    }
//};

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, cnt = 0, res = 0, n = nums.size();
        // 使用 while 循环直到 r 遍历完整个数组
        while (r < n) {
            // 如果当前元素是 0，增加计数
            if (nums[r] == 0) {
                cnt++;
            }
            // 当遇到超过一个 0 时，移动 l 指针
            // 直到窗口中最多只有一个 0
            while (cnt > 1) {
                if (nums[l] == 0) {
                    cnt--; // 如果 l 指针的元素是 0，减少计数
                }
                l++; // 移动 l 指针
            }
            // 更新结果 res，为当前窗口的长度（r - l）
            res = max(res, r - l);
            // 移动 r 指针，继续检查下一个元素
            r++;
        }
        // 返回最长全 1 子数组的长度
        return res;
    }
};




// 示例函数，用于演示 Solution 类的 longestSubarray 方法
int main() {
    Solution solution;
    // 创建一个示例数组
    vector<int> nums = { 1, 1, 0, 1, 1, 0, 1 };
    // 调用 longestSubarray 方法并输出结果
    cout << "The length of the longest subarray with all elements being 1 after removing one element is: "
        << solution.longestSubarray(nums) << endl;

    return 0;
}