#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int interpolationSearch(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high && target >= nums[0] && target <= nums[high]) {
            int mid = low + (target - nums[low]) * (high - low) / (nums[high] - nums[low]);
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 10, 20, 30, 40, 50, 70, 80, 100, 110, 120, 130, 140 };
    int target = 50;

    int result = solution.interpolationSearch(nums, target);
    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}