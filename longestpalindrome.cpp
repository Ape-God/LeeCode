#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            int len1 = expandAroundCenter(s, i, i); // �������ȵĻ���
            int len2 = expandAroundCenter(s, i, i + 1); // ż�����ȵĻ���
            int len = max(len1, len2);
            if (len > maxLen) {
                start = i - (len - 1) / 2; // ����������Ӵ�����ʼλ��
                maxLen = len; // ���������
            }
        }
        return s.substr(start, maxLen); // ������Ļ����Ӵ�
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            --L;
            ++R;
        }
        return R - L - 1; // ������L��RΪ�˵�Ļ����Ӵ��ĳ���
    }
};

int main() {
    Solution solution;
    string s = "babad"; // ʾ���ַ���

    string longest = solution.longestPalindrome(s);
    cout << "The longest palindrome substring is: " << longest << endl;

    return 0;
}