#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    // �������������ڴ��ַ�������ȡ����
    string getDigits(string& s, size_t& ptr) {
        string ret = "";
        // ֻҪ��ǰ�ַ������֣��ͽ�����ӵ������ַ���������ָ��
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    // �������������ڽ��ַ�����������Ϊһ���ַ���
    string getString(vector<string>& v) {
        string ret;
        // �����ַ����������������ַ�����������
        for (const auto& s : v) {
            ret += s;
        }
        return ret;
    }

    string decodeString(string s) {
        vector<string> stk; // ʹ���ַ���������Ϊջ
        size_t ptr = 0; // ��ʼ��ָ��

        // ѭ��ֱ�������������ַ���
        while (ptr < s.size()) {
            char cur = s[ptr]; // ��ǰ�ַ�
            if (isdigit(cur)) {
                // �����ǰ�ַ������֣�����ȡ���ֲ���������ջ
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            }
            else if (isalpha(cur) || cur == '[') {
                // �����ǰ�ַ�����ĸ�������ţ���������ջ
                // ע�⣺������߼�������Ϊ������Ӧ�ñ��һ�������еĿ�ʼ�����������뵥���ַ�
                stk.push_back(string(1, s[ptr++]));
            }
            else if (cur == ']') {
                // ���������ţ������ظ�
                ++ptr; // ����ָ������������
                // ��ջ�е���ֱ�����������ţ������������ַ�����ת˳��
                vector<string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end()); // ��ת���ַ�������
                stk.pop_back(); // ����������
                // ջ��Ԫ�����ظ�������ת��Ϊ����
                int repTime = stoi(stk.back());
                stk.pop_back(); // �����ظ�����
                string t, o = getString(sub); // ��ȡ���ַ���
                // �ظ������ַ���
                while (repTime--) t += o;
                // ������õ��ַ�������ջ
                stk.push_back(t);
            }
        }

        // ����ջ�е������ַ��������ؽ������ַ���
        return getString(stk);
    }
};

// ʾ��������������ʾ Solution ��� decodeString ����
int main() {
    Solution solution;
    // ����һ��ʾ���ַ���
    string s = "3[a]2[bc]";

    // ���� decodeString ������������
    string result = solution.decodeString(s);
    cout << "Decoded string: " << result << endl;

    return 0;
}