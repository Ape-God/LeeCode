#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // 主函数，用于计算每日气温后几天会出现更高的气温
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0); // 初始化答案数组，填充0
        stack<int> s; // 使用栈存储气温数组的索引

        for (int i = 0; i < temperatures.size(); ++i) {
            // 当栈不为空且当前温度高于栈顶元素对应的温度
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                // 弹出栈顶元素，计算天数差，并更新答案数组
                int index = s.top();
                s.pop();
                ans[index] = i - index;
            }
            // 将当前索引入栈
            s.push(i);
        }

        return ans; // 返回答案数组
    }
};

// 示例函数，用于演示 Solution 类的 dailyTemperatures 方法
int main() {
    Solution solution;
    // 创建一个示例气温数组
    vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
    // 调用 dailyTemperatures 方法并输出结果
    vector<int> ans = solution.dailyTemperatures(temperatures);
    cout << "Days after which a higher temperature will appear: ";
    for (int day : ans) {
        cout << day << " ";
    }
    cout << endl;

    return 0;
}