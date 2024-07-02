#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(&result, nums, 0);
        return result;
    }

private:
    void backtrack(vector<vector<int>>* result, vector<int>& nums, int first) {
        if (first == nums.size()) {
            result->emplace_back(nums);
            return;
        }
        for (int i = first; i < nums.size(); ++i) {
            swap(nums[i], nums[first]); // 交换当前元素到首位
            backtrack(result, nums, first + 1); // 递归生成剩余元素的排列
            swap(nums[i], nums[first]); // 回溯
        }
    }
};

// 打印全排列结果的辅助函数
void printPermutations(const vector<vector<int>>& perms) {
    for (const auto& perm : perms) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;
    vector<int> nums = { 1, 2, 3 };

    vector<vector<int>> perms = solution.permute(nums);
    printPermutations(perms);

    return 0;
}