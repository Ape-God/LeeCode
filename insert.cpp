#include <iostream>
#include <vector>
#include <algorithm> // 用于 std::min 和 std::max
using namespace std;

// 函数用于合并区间并插入新区间
//std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
//    std::vector<std::vector<int>> result;
//    int i = 0;
//
//    // 插入前处理：添加所有结束点小于newInterval开始点的区间
//    while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
//        result.push_back(intervals[i]);
//        ++i;
//    }
//
//    // 处理重叠区间并合并
//    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
//        newInterval[0] = std::min(newInterval[0], intervals[i][0]);
//        newInterval[1] = std::max(newInterval[1], intervals[i][1]);
//        ++i;
//    }
//
//    // 添加合并后的区间
//    result.push_back(newInterval);
//
//    // 添加剩余的区间
//    for (; i < intervals.size(); ++i) {
//        result.push_back(intervals[i]);
//    }
//
//    return result;
//}

vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
    vector<vector<int>> ans;
    int n = a.size(), i = 0;
    while (i < n && a[i][1] < b[0]) {
        ans.push_back(a[i++]);
    }
    if (i < n) {
        b[0] = min(a[i][0], b[0]);
        while (i < n && a[i][0] <= b[1]) {
            b[1] = max(a[i++][1], b[1]);
        }
    }
    ans.push_back(b);
    while (i < n) {
        ans.push_back(a[i++]);
    }
    return ans;
}




// 主函数，用于测试insert函数
int main() {
    std::vector<std::vector<int>> intervals = { {1, 3}, {6, 9} };
    std::vector<int> newInterval = { 2, 5 };
    std::vector<std::vector<int>> updatedIntervals = insert(intervals, newInterval);

    // 打印结果
    for (const auto& interval : updatedIntervals) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "]" << std::endl;
    }

    return 0;
}