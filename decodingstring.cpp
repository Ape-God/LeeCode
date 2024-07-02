#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    // 辅助函数，用于从字符串中提取数字
    string getDigits(string& s, size_t& ptr) {
        string ret = "";
        // 只要当前字符是数字，就将它添加到返回字符串并递增指针
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    // 辅助函数，用于将字符串向量连接为一个字符串
    string getString(vector<string>& v) {
        string ret;
        // 遍历字符串向量，将所有字符串连接起来
        for (const auto& s : v) {
            ret += s;
        }
        return ret;
    }

    string decodeString(string s) {
        vector<string> stk; // 使用字符串向量作为栈
        size_t ptr = 0; // 初始化指针

        // 循环直到遍历完整个字符串
        while (ptr < s.size()) {
            char cur = s[ptr]; // 当前字符
            if (isdigit(cur)) {
                // 如果当前字符是数字，则提取数字并将其推入栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            }
            else if (isalpha(cur) || cur == '[') {
                // 如果当前字符是字母或左括号，将其推入栈
                // 注意：这里的逻辑有误，因为左括号应该标记一个新序列的开始，而不是推入单个字符
                stk.push_back(string(1, s[ptr++]));
            }
            else if (cur == ']') {
                // 遇到右括号，处理重复
                ++ptr; // 递增指针跳过右括号
                // 从栈中弹出直到遇到左括号，并将弹出的字符串反转顺序
                vector<string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end()); // 反转子字符串向量
                stk.pop_back(); // 弹出左括号
                // 栈顶元素是重复次数，转换为整数
                int repTime = stoi(stk.back());
                stk.pop_back(); // 弹出重复次数
                string t, o = getString(sub); // 获取子字符串
                // 重复构造字符串
                while (repTime--) t += o;
                // 将构造好的字符串推入栈
                stk.push_back(t);
            }
        }

        // 连接栈中的所有字符串，返回解码后的字符串
        return getString(stk);
    }
};

// 示例函数，用于演示 Solution 类的 decodeString 方法
int main() {
    Solution solution;
    // 创建一个示例字符串
    string s = "3[a]2[bc]";

    // 调用 decodeString 方法并输出结果
    string result = solution.decodeString(s);
    cout << "Decoded string: " << result << endl;

    return 0;
}