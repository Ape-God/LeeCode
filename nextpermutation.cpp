#include <vector>
#include <algorithm> // 用于 reverse
#include <iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};


//class Solution {
//public:
//    void nextPermutation(vector<int>& nums) {
//        int n = nums.size();
//        // 步骤1：找到下降点
//        int i = n - 2;
//        while (i >= 0 && nums[i] >= nums[i + 1]) {
//            i--;
//        }
//
//        // 如果i < 0，说明数组是降序的，直接反转即可
//        if (i == -1) {
//            reverse(nums.begin(), nums.end());
//            return;
//        }
//
//        // 步骤2：找到大于下降点的最小元素并交换
//        int j = n - 1;
//        while (nums[j] <= nums[i]) {
//            j--;
//        }
//        swap(nums[i], nums[j]);
//
//        // 步骤3：反转下降点之后的所有元素
//        reverse(nums.begin() + i + 1, nums.end());
//    }
//};

// 主函数，用于测试
int main() {
    Solution solution;
    vector<int> nums = { 1, 2, 3 };
    solution.nextPermutation(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}