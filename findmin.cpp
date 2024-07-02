#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                // 中间元素比右边界元素大，说明最小值在mid的右边，包括mid和right
                left = mid + 1;
            }
            else {
                // 中间元素小于或等于右边界元素，最小值可能在mid的左边或mid自身
                right = mid;
            }
        }
        // 当left == right时，left和right都指向最小元素
        return nums[left];
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 4,5,6,7,0,1,2 }; // 示例数组

    int minVal = solution.findMin(nums);
    cout << "The minimum element in the rotated sorted array is: " << minVal << endl;

    return 0;
}