#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;

        int first = INT_MAX; // 第一个数，初始化为正无穷
        int second = INT_MAX; // 第二个数，初始化为正无穷

        for (int num : nums) {
            if (num <= first) {
                // 如果当前数小于或等于first，更新first为最小值
                first = num;
            }
            else if (num <= second) {
                // 如果当前数大于first且小于或等于second，更新second
                second = num;
            }
            else {
                // 如果当前数大于second，找到递增三元组
                return true;
            }
        }
        return false; // 没有找到递增三元组
    }
};

// 测试函数
void testSolution(Solution& solution, vector<int>& nums) {
    bool result = solution.increasingTriplet(nums);
    cout << "Does the array have an increasing triplet? " << (result ? "Yes" : "No") << endl;
}

int main() {
    Solution solution;
    vector<int> nums1 = { 1, 2, 3, 4, 5 };
    testSolution(solution, nums1);

    vector<int> nums2 = { 5, 4, 3, 2, 1 };
    testSolution(solution, nums2);

    vector<int> nums3 = { 1, 3, 2, 4, 6 };
    testSolution(solution, nums3);

    return 0;
}