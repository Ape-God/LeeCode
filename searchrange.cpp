#include <vector>
#include <iostream>
using namespace std;

//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int n = nums.size();
//        vector<int> result = { -1, -1 };
//
//        // 查找目标值的左侧边界
//        int left = 0, right = n - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] >= target) {
//                right = mid - 1;
//            }
//            else {
//                left = mid + 1;
//            }
//        }
//        if (left == n || nums[left] != target) {
//            return result; // 目标值不存在
//        }
//        result[0] = left; // 左侧边界
//
//        // 查找目标值的右侧边界
//        left = 0, right = n - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] <= target) {
//                left = mid + 1;
//            }
//            else {
//                right = mid - 1;
//            }
//        }
//        result[1] = right; // 右侧边界
//
//        return result;
//    }
//};


class Solution {
public:
    // 二分查找变种，用于查找目标值在数组中的最左或最右位置
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = nums.size() - 1, ans = (int)nums.size(); // 初始化左右指针和答案
        // 循环直到左右指针相遇
        while (left <= right) {
            int mid = left + (right - left) / 2; // 计算中间位置
            // 如果中间值大于目标值，或者它是小于等于目标值且我们正在找更小的值
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1; // 调整右边界并更新答案
                ans = mid;
            }
            else {
                left = mid + 1; // 否则调整左边界
            }
        }
        return ans; // 返回目标值的位置或数组之外的某个位置
    }

    // 查找目标值在数组中的起始和结束位置
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true); // 通过binarySearch查找最左位置
        int rightIdx = binarySearch(nums, target, false) - 1; // 通过binarySearch查找最右位置，减1调整为实际的索引

        // 检查找到的索引是否有效，并且对应位置的值确实为目标值
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx}; // 返回目标值的起始和结束位置
        }
        // 如果没有找到目标值，返回{-1, -1}
        return vector<int>{-1, -1};
    }
};



int main() {
    Solution solution;
    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    int target = 8;

    vector<int> result = solution.searchRange(nums, target);
    if (result[0] == -1) {
        cout << "The target " << target << " is not in the array." << endl;
    }
    else {
        cout << "The target " << target << " is located in the range: ["
            << result[0] << ", " << result[1] << "]" << endl;
    }

    return 0;
}