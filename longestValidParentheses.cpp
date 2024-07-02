#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // �������������ҳ����Ч�����Ӵ��ĳ���
    int longestValidParentheses(string s) {
        int maxLen = 0; // ��ʼ����󳤶�Ϊ0
        vector<int> stack; // ʹ��������Ϊջ
        stack.push_back(-1); // ��ʼ��ջ������һ��Ԫ����Ϊ-1����Ϊ�����ǰһ���ַ�������

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                // �����ǰ�ַ��������ţ���������ѹ��ջ
                stack.push_back(i);
            }
            else {
                // �����ǰ�ַ���������
                if (!stack.empty()) {
                    // ����ջ��Ԫ�أ����ջΪ�գ��򽫵�ǰ������Ϊ�µļ���ǰһ���ַ�������
                    stack.pop_back();
                    if (stack.empty()) {
                        stack.push_back(i);
                    }
                    else {
                        // ���㵱ǰ������ջ��Ԫ�������Ĳ�ֵ��������󳤶�
                        maxLen = max(maxLen, i - stack.back());
                    }
                }
            }
        }

        return maxLen; // ������󳤶�
    }
};

// ʾ��������������ʾ Solution ��� longestValidParentheses ����
int main() {
    Solution solution;
    // ����һ��ʾ���ַ���
    string s = ")()())";
    // ���� longestValidParentheses ������������
    int maxLength = solution.longestValidParentheses(s);
    cout << "The length of the longest valid parentheses substring is: " << maxLength << endl;

    return 0;
}