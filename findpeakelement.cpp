#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 如果 mid 元素的右边元素更大，那么峰值一定在 mid 右边
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }
            else {
                // 否则，峰值在 mid 左边或者就是 mid
                right = mid;
            }
        }
        // 当 left == right 时，left 和 right 都指向可能的峰值
        return left;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1, 2, 3, 1 }; // 示例数组

    int peakIndex = solution.findPeakElement(nums);
    cout << "The index of the peak element is: " << peakIndex << endl;

    return 0;
}