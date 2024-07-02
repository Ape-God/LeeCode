#include <iostream>
#include <vector>
#include <algorithm> // 用于 sort 和 max

using namespace std;

// 函数用于合并所有重叠的区间
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // 如果区间数组为空，直接返回空数组
    if (intervals.empty()) return {};

    // 根据起始端点对区间进行排序
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged; // 存储合并后的区间
    // 将第一个区间加入到merged数组
    merged.push_back(intervals[0]);

    // 遍历区间数组，从第二个区间开始
    for (const auto& interval : intervals) {
        // 如果当前区间的起始端点大于merged数组中最后一个区间的结束端点
        if (interval[0] > merged.back()[1]) {
            // 不重叠，直接添加到merged数组
            merged.push_back(interval);
        }
        else {
            // 否则，合并当前区间与merged数组中最后一个区间
            // 更新merged数组中最后一个区间的结束端点为两个区间的最大结束端点
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged; // 返回合并后的区间数组
}

class Solution {
public:
    // 合并重叠的区间
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; // 存储合并后的区间
        // 首先对区间按起始位置进行排序
        sort(intervals.begin(), intervals.end());

        // 初始化第一个区间的起始和结束位置
        int start = intervals[0][0], end = intervals[0][1];

        // 遍历排序后的区间
        for (int i = 1; i < intervals.size(); ++i) {
            // 如果当前区间的起始位置大于上一个区间的结束位置
            if (intervals[i][0] > end) {
                // 将当前区间加入结果数组，并更新起始和结束位置
                ans.push_back({ start, end });
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else {
                // 如果有重叠，更新结束位置为两个区间结束位置的最大值
                end = max(end, intervals[i][1]);
            }
        }
        // 将最后一个区间加入结果数组
        ans.push_back({ start, end });
        return ans; // 返回合并后的区间
    }
};



// 主函数，用于测试merge函数
int main() {
    vector<vector<int>> intervals = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
    vector<vector<int>> mergedIntervals = merge(intervals);

    // 打印结果
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}