#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // �����������ڼ�������������еĳ���
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length(); // ��ȡ�����ַ����ĳ���
        vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // ��ʼ����̬�滮����

        // ��1��ʼ����text1��dp[i][j]��ʾtext1��ǰi���ַ���text2��ǰj���ַ�������������еĳ���
        for (int i = 1; i <= m; i++) {
            char c1 = text1.at(i - 1); // ��ȡtext1�ĵ�i���ַ�
            // ��1��ʼ����text2
            for (int j = 1; j <= n; j++) {
                char c2 = text2.at(j - 1); // ��ȡtext2�ĵ�j���ַ�

                // �����ǰ�ַ���ȣ���ô����������г��ȼ�1
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                // �����ǰ�ַ����ȣ�ȡ��߻��ϱ߸��ӵĽϴ�ֵ
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // ����dp[m][n���������ַ���������������еĳ���
        return dp[m][n];
    }
};

// ʾ��������������ʾ Solution ��� longestCommonSubsequence ����
int main() {
    Solution solution;
    // ���� longestCommonSubsequence ������������
    string text1 = "abcde";
    string text2 = "ace";
    cout << "Length of longest common subsequence: " << solution.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}