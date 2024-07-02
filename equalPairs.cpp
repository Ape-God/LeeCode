#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(); // 获取矩阵 grid 的大小，即行数或列数

        // 创建一个 map，用于存储每一行的元素排列（作为 vector）及其出现次数
        map<vector<int>, int> cnt;

        // 遍历 grid 中的每一行
        for (auto row : grid) {
            // 由于 map 的键需要唯一，这里隐含地需要每一行都是排好序的，
            // 但原代码没有排序，这是潜在的逻辑错误
            cnt[row]++; // 将每一行的元素排列作为键，出现次数作为值，存入 map
        }

        int res = 0; // 初始化结果计数器为 0

        // 遍历 grid 的每一列
        for (int j = 0; j < n; ++j) {
            vector<int> arr; // 用于存储当前列的元素
            // 提取 grid 的第 j 列
            for (int i = 0; i < n; ++i) {
                arr.emplace_back(grid[i][j]);
            }
            // 检查当前列的元素排列是否在 map 中存在
            // 如果存在，累加该排列出现的次数到结果计数器 res
            if (cnt.find(arr) != cnt.end()) {
                res += cnt[arr];
            }
        }

        // 返回相等行列对的总数
        return res;
    }
};



// 示例函数，用于演示 Solution 类的 equalPair 方法
int main() {
    Solution solution;
    // 创建一个示例矩阵
    vector<vector<int>> grid = {
        {3, 2, 1},
        {1, 2, 3},
        {2, 1, 3}
    };

    // 调用 equalPair 方法并输出结果
    int result = solution.equalPairs(grid);
    cout << "The number of equal row-column pairs is: " << result << endl;

    return 0;
}