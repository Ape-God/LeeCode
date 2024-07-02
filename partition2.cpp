#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//class Solution {
//public:
//    // 回文串分割函数
//    void backtrack(int start, string s, vector<string>& current, vector<vector<string>>& result) {
//        if (start == s.size()) {
//            // 如果已经处理到字符串末尾，将当前分割方案添加到结果中
//            result.push_back(current);
//            return;
//        }
//
//        for (int end = start; end < s.size(); ++end) {
//            // 如果从 start 到 end 的子串是回文串
//            if (isPalindrome(s, start, end)) {
//                // 将子串添加到当前分割方案中
//                current.push_back(s.substr(start, end - start + 1));
//                // 继续递归处理后面的字符串
//                backtrack(end + 1, s, current, result);
//                // 回溯，移除当前子串，尝试其他分割方案
//                current.pop_back();
//            }
//        }
//    }
//
//    // 判断是否是回文串的辅助函数
//    bool isPalindrome(const string& s, int start, int end) {
//        while (start < end) {
//            if (s[start++] != s[end--]) {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    // 公开的分割回文串函数
//    vector<vector<string>> partition(string s) {
//        vector<vector<string>> result; // 存储所有可能的分割方案
//        vector<string> current; // 存储当前的分割方案
//        backtrack(0, s, current, result); // 从第一个字符开始递归
//        return result;
//    }
//};


class Solution {
private:
    vector<vector<int>> f;  // f[i][j] 用于存储 s[i...j] 是否为回文串
    vector<vector<string>> ret;  // 存储所有可能的分割方案
    vector<string> ans;  // 存储当前的分割方案
    int n;  // 字符串 s 的长度

public:
    // 深度优先搜索函数，用于找出所有可能的分割方案
    void dfs(const string& s, int i) {
        if (i == n) {  // 如果已经处理到字符串末尾
            ret.push_back(ans);  // 将当前分割方案添加到结果中
            return;
        }
        // 尝试从 i 开始的所有可能的回文子串
        for (int j = i; j < n; ++j) {
            if (f[i][j]) {  // 如果 s[i...j] 是回文串
                ans.push_back(s.substr(i, j - i + 1));  // 将子串添加到当前分割方案
                dfs(s, j + 1);  // 递归处理后面的字符串
                ans.pop_back();  // 回溯，移除当前子串，尝试其他分割方案
            }
        }
    }

    // 公开的分割回文串函数
    vector<vector<string>> partition(string s) {
        n = s.size();  // 获得字符串长度
        f.assign(n, vector<int>(n, true));  // 初始化 f，填充为 true

        // 构建 f，f[i][j] 表示 s[i...j] 是否为回文串
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        dfs(s, 0);  // 从第一个字符开始递归
        return ret;  // 返回所有可能的分割方案
    }
};



// 示例调用
int main() {
    Solution solution;
    string s1 = "aab";
    vector<vector<string>> result1 = solution.partition(s1);
    // 打印输出示例1
    for (const auto& part : result1) {
        for (const auto& str : part) {
            cout << str << " ";
        }
        cout << endl;
    }

    string s2 = "a";
    vector<vector<string>> result2 = solution.partition(s2);
    // 打印输出示例2
    for (const auto& part : result2) {
        for (const auto& str : part) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}