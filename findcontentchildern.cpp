#include <iostream>
#include <vector>
#include <algorithm> // 用于 sort
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // 对孩子的胃口值进行排序
        sort(s.begin(), s.end()); // 对饼干的尺寸进行排序
        int i = 0, j = 0, count = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) { // 如果饼干尺寸足够
                count++;         // 孩子被满足
                i++;             // 移动到下一个孩子的胃口值
                j++;             // 移动到下一块饼干
            }
            else {
                j++; // 否则，尝试下一块饼干
            }
        }
        return count; // 返回满足的孩子数量
    }
};

// 主函数，用于测试
int main() {
    Solution solution;
    vector<int> g = { 1, 2, 3 };
    vector<int> s = { 1, 1 };
    cout << "Number of content children: " << solution.findContentChildren(g, s) << endl; // 应输出 1

    return 0;
}