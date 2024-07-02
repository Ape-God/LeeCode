#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false); // ʹ�� vector �������
        dp[0] = true; // ���ַ������Ա����

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    string s = "leetcode";
    vector<string> wordDict = { "leet", "code" };
    cout << (solution.wordBreak(s, wordDict) ? "true" : "false") << endl;
    return 0;
}