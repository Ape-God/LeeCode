#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 主函数，用于找到所有p的异位词的子串的起始索引
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size(); // 获取s和p的长度

        // 如果s的长度小于p，直接返回空向量，因为不可能有异位词子串
        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans; // 用于存储结果的向量
        vector<int> sCount(26, 0); // 初始化s的字符计数器，基于a-z的ASCII值
        vector<int> pCount(26, 0); // 初始化p的字符计数器

        // 计算p中每个字符的计数
        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a']; // s中的第一个窗口字符计数
            ++pCount[p[i] - 'a'];
        }

        // 如果s的第一个窗口字符计数与p相同，记录起始索引0
        if (sCount == pCount) {
            ans.emplace_back(0);
        }

        // 滑动窗口，从s的第二个字符开始
        for (int i = 0; i < sLen - pLen; ++i) {
            // 从窗口左侧移除一个字符，并更新计数
            --sCount[s[i] - 'a'];
            // 将窗口右侧的新字符添加到窗口，并更新计数
            ++sCount[s[i + pLen] - 'a'];

            // 如果更新后的窗口字符计数与p相同，记录当前窗口的起始索引
            if (sCount == pCount) {
                ans.emplace_back(i + 1);
            }
        }

        // 返回所有异位词子串的起始索引
        return ans;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if (m < n) {
            return {};
        }
        vector<int> ans, sCount(26), pCount(26);
        for (auto c : p) {
            pCount[c - 'a']++;
        }
        vector<int> res;
        for (int i = 0; i < m; ++i) {
            sCount[s[i] - 'a']++;
            if (i >= n) {
                sCount[s[i - n] - 'a']--;
            }
            if (sCount == pCount) {
                res.push_back(i - n + 1);
            }
        }
        return res;
    }
};

// 示例函数，用于演示 Solution 类的 findAnagrams 方法
int main() {
    Solution solution;
    // 创建一个示例字符串s和模式字符串p
    string s = "abba";
    string p = "bab";
    // 调用 findAnagrams 方法并输出结果
    vector<int> indices = solution.findAnagrams(s, p);
    cout << "Start indices of anagram substrings: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}