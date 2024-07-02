#include <iostream>
#include <vector>
#include <algorithm> // 用于 std::sort
using namespace std;

int findMinArrowShots(std::vector<std::vector<int>>& points) {
    if (points.empty()) return 0;

    // 根据气球的结束坐标进行排序
    std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
        });

    int count = 1; // 至少需要一支箭
    int end = points[0][1]; // 当前箭的最右端

    for (int i = 1; i < points.size(); ++i) {
        // 如果当前气球的开始坐标大于 end，说明需要新的箭
        if (points[i][0] > end) {
            count++;
            end = points[i][1]; // 更新最右端
        }
        // 如果当前气球被之前的箭引爆，则不需要新的箭
        else if (points[i][1] < end) {
            end = points[i][1]; // 更新当前箭的最右端
        }
    }

    return count;
}

int main() {
    std::vector<std::vector<int>> points = { {10, 16}, {2, 8}, {1, 6}, {7, 12} };
    int result = findMinArrowShots(points);
    std::cout << "The minimum number of arrows needed is: " << result << std::endl; // 应该输出 2
    return 0;
}