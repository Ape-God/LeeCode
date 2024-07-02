#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, n = nums.size();
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return target == nums[0] ? 0 : -1;
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid; // 找到目标值，返回索引
            }

            // 判断左半部分是否有序
            if (nums[left] <= nums[mid]) {
                // 左半部分有序
                if (target >= nums[left] && target < nums[mid]) {
                    // 目标值在左半部分
                    right = mid - 1;
                }
                else {
                    // 目标值在右半部分
                    left = mid + 1;
                }
            }
            else {
                // 右半部分有序
                if (target > nums[mid] && target <= nums[right]) {
                    // 目标值在右半部分
                    left = mid + 1;
                }
                else {
                    // 目标值在左半部分
                    right = mid - 1;
                }
            }
        }
        return -1; // 未找到目标值，返回-1
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    int target = 0;

    int index = solution.search(nums, target);
    if (index != -1) {
        cout << "The target " << target << " is at index: " << index << endl;
    }
    else {
        cout << "The target " << target << " is not in the array." << endl;
    }

    return 0;
}