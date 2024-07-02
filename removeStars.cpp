#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> st; // 使用栈来存储非星号字符
        string result; // 用于存储最终结果的字符串

        for (char c : s) {
            if (c != '*') {
                // 如果当前字符不是星号，则推入栈中
                st.push(c);
            }
            else {
                // 如果当前字符是星号，且栈不为空，则弹出栈顶元素
                if (!st.empty()) {
                    st.pop();
                }
            }
        }

        // 将栈中的元素反转到结果字符串中
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // 由于我们从栈顶开始添加，所以结果字符串是反向的，需要反转
        reverse(result.begin(), result.end());

        return result;
    }
};

// 示例函数，用于演示 Solution 类的 removeStars 方法
int main() {
    Solution solution;
    // 创建一个示例字符串
    string s = "a**b*cd*";

    // 调用 removeStars 方法并输出结果
    string result = solution.removeStars(s);
    cout << "The string after removing stars: \"" << result << "\"" << endl;

    return 0;
}