#include <string>
#include <stack>
#include <cctype>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int sign = 1;

        int ret = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
            }
            else if (s[i] == '+') {
                sign = ops.top();
                i++;
            }
            else if (s[i] == '-') {
                sign = -ops.top();
                i++;
            }
            else if (s[i] == '(') {
                ops.push(sign);
                i++;
            }
            else if (s[i] == ')') {
                ops.pop();
                i++;
            }
            else {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
};



// 主函数，用于测试 calculate 函数
int main() {
    std::string expression = "(1+(4+5+2)-3)+(6+8)";
    Solution solution;
    std::cout << "The result of the expression \"" << expression << "\" is " << solution.calculate(expression) << std::endl;
    return 0;
}