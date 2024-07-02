#include <iostream>
#include <stack>
#include <string>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool isMatch(char left, char right) {
        return (left == '(' && right == ')') ||
            (left == '{' && right == '}') ||
            (left == '[' && right == ']');
    }

    bool isValid(string s) {
        stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            }
            else if (c == ')' || c == '}' || c == ']') {
                if (stack.empty() || !isMatch(stack.top(), c)) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }
};


int main() {
    string s = "{[]}()";
    Solution solution;
    cout << "The string \"" << s << "\" is " << (solution.isValid(s) ? "valid" : "invalid") << endl;
    return 0;
}