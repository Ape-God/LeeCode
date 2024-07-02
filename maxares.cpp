#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 主函数，用于找出一个柱状图中的最大矩形面积
    int maxArea(vector<int>& height) {
        int max_area = 0; // 初始化最大面积为0
        int left = 0, right = height.size() - 1; // 初始化左右指针

        // 使用 while 循环，当左指针小于右指针时继续
        while (left < right) {
            // 计算当前矩形的面积，其长为右指针与左指针之间的距离
            // 高为左右指针指向的柱状图中的较小值
            int curr_area = min(height[left], height[right]) * abs(right - left);
            // 更新最大面积
            max_area = max(max_area, curr_area);

            // 移动矮的那根柱子的指针，缩小搜索范围
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        // 返回计算出的最大矩形面积
        return max_area;
    }
};

// 示例测试
#include <iostream>

int main() {
    Solution solution;
    std::vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    int max_area = solution.maxArea(height);
    std::cout << "Maximum water area: " << max_area << std::endl;
    return 0;
}