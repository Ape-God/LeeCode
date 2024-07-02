#include <iostream>
#include <unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charCount;
        int baseLength = 0, oddCount = 0;

        // 统计每个字符出现的次数
        for (char c : s) {
            charCount[c]++;
        }

        // 计算基础长度和奇数个字符的数量
        for (auto& pair : charCount) {
            baseLength += pair.second / 2 * 2; // 配对的字符
            if (pair.second % 2 == 1) {
                oddCount++; // 奇数个字符
            }
        }

        // 返回最长回文串的长度，基础长度加上奇数个字符的数量
        return baseLength + (oddCount > 0 ? 1 : 0);
    }
};

// 主函数，用于测试
int main() {
    Solution solution;
    string s1 = "abccccdd";
    cout << "Longest palindrome length: " << solution.longestPalindrome(s1) << endl; // 应输出 7

    string s2 = "a";
    cout << "Longest palindrome length: " << solution.longestPalindrome(s2) << endl; // 应输出 1

    return 0;
}