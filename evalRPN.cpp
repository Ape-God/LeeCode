#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> values;
        for (const std::string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // ִ������
                int right = values.top();
                values.pop();
                int left = values.top();
                values.pop();
                switch (token[0]) {
                case '+': values.push(left + right); break;
                case '-': values.push(left - right); break;
                case '*': values.push(left * right); break;
                case '/':
                    // �������0�����
                    if (right != 0) {
                        values.push(left / right);
                    }
                    else {
                        throw std::runtime_error("Division by zero.");
                    }
                    break;
                }
            }
            else {
                // ѹ����ֵ
                values.push(std::stoi(token));
            }
        }
        return values.top(); // ���ջ�е�Ԫ�ؼ�Ϊ���ʽ�ļ�����
    }
};

int main() {
    Solution solution;
    std::vector<std::string> tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "17", "+", "5" };

    int result = solution.evalRPN(tokens);
    std::cout << "The result of the RPN expression is: " << result << std::endl;

    return 0;
}