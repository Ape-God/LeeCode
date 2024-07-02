#include <iostream>
#include <vector>
#include <algorithm> // 包含 std::sort 函数

class Solution {
public:
    // 计算 h 指数的方法
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int h = 0, i = citations.size() - 1;
        while (i >= 0 && citations[i] > h) {
            h++;
            i--;
        }
        return h;
    }
};

// 主函数，用于调用 hIndex 方法并打印结果
int main() {
    Solution solution;
    // 示例向量，表示论文的引用次数
    std::vector<int> citations = { 3, 0, 6, 1, 5 };
    // 调用 hIndex 方法并打印结果
    int hIndex = solution.hIndex(citations);
    std::cout << "The h-index is: " << hIndex << std::endl;
    return 0;
}