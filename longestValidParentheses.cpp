#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 主函数，用于找出最长有效括号子串的长度
    int longestValidParentheses(string s) {
        int maxLen = 0; // 初始化最大长度为0
        vector<int> stack; // 使用向量作为栈
        stack.push_back(-1); // 初始化栈，将第一个元素设为-1，作为假想的前一个字符的索引

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                // 如果当前字符是左括号，将其索引压入栈
                stack.push_back(i);
            }
            else {
                // 如果当前字符是右括号
                if (!stack.empty()) {
                    // 弹出栈顶元素，如果栈为空，则将当前索引作为新的假想前一个字符的索引
                    stack.pop_back();
                    if (stack.empty()) {
                        stack.push_back(i);
                    }
                    else {
                        // 计算当前索引与栈顶元素索引的差值，更新最大长度
                        maxLen = max(maxLen, i - stack.back());
                    }
                }
            }
        }

        return maxLen; // 返回最大长度
    }
};

// 示例函数，用于演示 Solution 类的 longestValidParentheses 方法
int main() {
    Solution solution;
    // 创建一个示例字符串
    string s = ")()())";
    // 调用 longestValidParentheses 方法并输出结果
    int maxLength = solution.longestValidParentheses(s);
    cout << "The length of the longest valid parentheses substring is: " << maxLength << endl;

    return 0;
}