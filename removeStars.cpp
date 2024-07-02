#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> st; // ʹ��ջ���洢���Ǻ��ַ�
        string result; // ���ڴ洢���ս�����ַ���

        for (char c : s) {
            if (c != '*') {
                // �����ǰ�ַ������Ǻţ�������ջ��
                st.push(c);
            }
            else {
                // �����ǰ�ַ����Ǻţ���ջ��Ϊ�գ��򵯳�ջ��Ԫ��
                if (!st.empty()) {
                    st.pop();
                }
            }
        }

        // ��ջ�е�Ԫ�ط�ת������ַ�����
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // �������Ǵ�ջ����ʼ��ӣ����Խ���ַ����Ƿ���ģ���Ҫ��ת
        reverse(result.begin(), result.end());

        return result;
    }
};

// ʾ��������������ʾ Solution ��� removeStars ����
int main() {
    Solution solution;
    // ����һ��ʾ���ַ���
    string s = "a**b*cd*";

    // ���� removeStars ������������
    string result = solution.removeStars(s);
    cout << "The string after removing stars: \"" << result << "\"" << endl;

    return 0;
}