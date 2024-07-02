#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//class Solution {
//public:
//    // 回溯函数，用于找出所有可能的组合
//    void backtrack(int start, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
//        if (target == 0) {
//            // 如果当前目标值为0，说明找到了一个有效的组合
//            result.push_back(current);
//            return;
//        }
//
//        for (int i = start; i < candidates.size(); ++i) {
//            // 如果当前数字大于剩余目标值，不需要继续搜索
//            if (candidates[i] > target) break;
//
//            // 选择当前数字并递归搜索
//            current.push_back(candidates[i]);
//            backtrack(i, target - candidates[i], candidates, current, result);  // 允许重复选择同一个数字
//            current.pop_back();  // 回溯，移除当前数字
//        }
//    }
//
//    // 公开的组合总和函数
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        sort(candidates.begin(), candidates.end());  // 排序candidates数组，以便进行剪枝
//        vector<int> current;  // 当前组合
//        vector<vector<int>> result;  // 所有组合的列表
//        backtrack(0, target, candidates, current, result);  // 从索引0开始递归搜索
//        return result;
//    }
//};


class Solution {
public:
    // 深度优先搜索（DFS）函数，用于找出所有可能的组合
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        // 如果索引 idx 等于 candidates 的大小，说明已经尝试了所有数字，返回
        if (idx == candidates.size()) {
            return;
        }
        // 如果 target 为 0，说明当前组合是和为目标值的一个有效组合，添加到结果 ans 中
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 尝试不选择当前数字 candidates[idx]，继续搜索
        dfs(candidates, target, ans, combine, idx + 1);
        // 如果剩余目标值大于等于当前数字，选择当前数字
        if (target - candidates[idx] >= 0) {
            // 将当前数字添加到组合中
            combine.emplace_back(candidates[idx]);
            // 递归调用 dfs，更新剩余目标值为 target - candidates[idx]
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            // 回溯，移除组合中的最后一个数字，以便尝试其他可能的组合
            combine.pop_back();
        }
    }

    // 组合总和函数，返回所有可能的组合
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // 存储所有可能的组合结果
        vector<int> combine; // 存储当前的组合
        // 从索引 0 开始，调用 dfs 进行深度优先搜索
        dfs(candidates, target, ans, combine, 0);
        return ans; // 返回所有可能的组合结果
    }
};


// 示例调用
int main() {
    Solution solution;
    vector<int> candidates1 = { 2, 3, 6, 7 };
    int target1 = 7;
    vector<vector<int>> result1 = solution.combinationSum(candidates1, target1);
    // 打印输出示例1
    for (const auto& comb : result1) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<int> candidates2 = { 2, 3, 5 };
    int target2 = 8;
    vector<vector<int>> result2 = solution.combinationSum(candidates2, target2);
    // 打印输出示例2
    for (const auto& comb : result2) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<int> candidates3 = { 2 };
    int target3 = 1;
    vector<vector<int>> result3 = solution.combinationSum(candidates3, target3);
    // 打印输出示例3（空结果）
    cout << "No combinations found." << endl;

    return 0;
}