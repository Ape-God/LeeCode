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
            backtrack(cur + "(", left + 1, right, max, result); // ʹ��cur + "("
        }
        if (right < left) {
            backtrack(cur + ")", left, right + 1, max, result); // ʹ��cur + ")"
        }
    }
};

// ��ӡ������ϵĸ�������
void printParenthesis(const vector<string>& parenthesis) {
    for (const auto& p : parenthesis) {
        cout << p << endl;
    }
}

int main() {
    Solution solution;
    int n = 3; // �����޸����ֵ�����Բ�ͬ������
    vector<string> result = solution.generateParenthesis(n);
    printParenthesis(result);
    return 0;
}