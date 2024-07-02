#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(const vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if (total_sum % 2 != 0) return false; // 如果总和不是偶数，则无法平分
        int target = total_sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true; // 0 元是可达的

        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }
        }

        return dp[target];
    }
};

void testSolution(Solution& solution, const vector<int>& nums) {
    bool result = solution.canPartition(nums);
    cout << "Can the set be partitioned into two equal sum subsets? "
        << (result ? "Yes" : "No") << endl;
}


int main() {
    Solution solution;
    vector<int> nums1 = { 1, 5, 11, 5 };
    testSolution(solution, nums1);

    vector<int> nums2 = { 1, 2, 3, 5 };
    testSolution(solution, nums2);

    return 0;
}