#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack("", 0, 0, n, result);
        return result;
    }

private:
    void backtrack(string cur, int left, int right, int max, vector<string>& result) {
        if (cur.length() == 2 * max) {
            result.push_back(cur);
            return;
        }
        if (left < max) {
            backtrack(cur + "(", left + 1, right, max, result); // 使用cur + "("
        }
        if (right < left) {
            backtrack(cur + ")", left, right + 1, max, result); // 使用cur + ")"
        }
    }
};

// 打印括号组合的辅助函数
void printParenthesis(const vector<string>& parenthesis) {
    for (const auto& p : parenthesis) {
        cout << p << endl;
    }
}

int main() {
    Solution solution;
    int n = 3; // 可以修改这个值来测试不同的输入
    vector<string> result = solution.generateParenthesis(n);
    printParenthesis(result);
    return 0;
}