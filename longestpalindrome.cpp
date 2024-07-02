#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            int len1 = expandAroundCenter(s, i, i); // 奇数长度的回文
            int len2 = expandAroundCenter(s, i, i + 1); // 偶数长度的回文
            int len = max(len1, len2);
            if (len > maxLen) {
                start = i - (len - 1) / 2; // 更新最长回文子串的起始位置
                maxLen = len; // 更新最长长度
            }
        }
        return s.substr(start, maxLen); // 返回最长的回文子串
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            --L;
            ++R;
        }
        return R - L - 1; // 返回以L和R为端点的回文子串的长度
    }
};

int main() {
    Solution solution;
    string s = "babad"; // 示例字符串

    string longest = solution.longestPalindrome(s);
    cout << "The longest palindrome substring is: " << longest << endl;

    return 0;
}