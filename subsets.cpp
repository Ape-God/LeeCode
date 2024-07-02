#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    // 回溯函数，用于生成所有可能的子集
    void backtrack(int index, vector<int>& current, vector<vector<int>>& result, const vector<int>& nums) {
        // 将当前的子集添加到结果中
        result.push_back(current);
        // 从 index 开始，尝试添加数组 nums 中的元素到当前子集
        for (int i = index; i < nums.size(); ++i) {
            // 添加 nums[i] 到当前子集
            current.push_back(nums[i]);
            // 递归调用，使用 i + 1 作为下一个起始索引
            backtrack(i + 1, current, result, nums);
            // 回溯，移除当前添加的元素，以尝试其他组合
            current.pop_back();
        }
    }

    // 公开的子集函数
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;  // 存储所有可能的子集
        vector<int> current;  // 存储当前的子集
        // 从索引 0 开始，调用回溯函数生成所有子集
        backtrack(0, current, result, nums);
        // 返回所有可能的子集
        return result;
    }
};

// 示例调用
int main() {
    Solution solution;
    vector<int> nums1 = { 1, 2, 3 };
    vector<vector<int>> subsets1 = solution.subsets(nums1);
    // 打印输出示例1
    for (const auto& subset : subsets1) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "[]\n";
    }

    vector<int> nums2 = { 0 };
    vector<vector<int>> subsets2 = solution.subsets(nums2);
    // 打印输出示例2
    for (const auto& subset : subsets2) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "[]\n";
    }

    return 0;
}