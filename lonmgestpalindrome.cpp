#include <iostream>
#include <unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charCount;
        int baseLength = 0, oddCount = 0;

        // ͳ��ÿ���ַ����ֵĴ���
        for (char c : s) {
            charCount[c]++;
        }

        // ����������Ⱥ��������ַ�������
        for (auto& pair : charCount) {
            baseLength += pair.second / 2 * 2; // ��Ե��ַ�
            if (pair.second % 2 == 1) {
                oddCount++; // �������ַ�
            }
        }

        // ��������Ĵ��ĳ��ȣ��������ȼ����������ַ�������
        return baseLength + (oddCount > 0 ? 1 : 0);
    }
};

// �����������ڲ���
int main() {
    Solution solution;
    string s1 = "abccccdd";
    cout << "Longest palindrome length: " << solution.longestPalindrome(s1) << endl; // Ӧ��� 7

    string s2 = "a";
    cout << "Longest palindrome length: " << solution.longestPalindrome(s2) << endl; // Ӧ��� 1

    return 0;
}