#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    string minWindow(string s, string t) {
//        unordered_map<char, int> need, have;
//        // 记录t中每个字符出现的次数
//        for (char c : t) {
//            need[c]++;
//        }
//
//        int left = 0, right = 0;
//        int valid = 0; // 表示当前窗口中满足条件的字符数
//        int minLen = INT_MAX, minLeft = 0;
//        string res;
//
//        while (right < s.size()) {
//            // 添加s[right]到当前窗口
//            have[s[right]]++;
//            if (need.find(s[right]) != need.end() && have[s[right]] <= need[s[right]]) {
//                valid++;
//            }
//
//            // 尝试缩小窗口直到当前窗口不再满足条件
//            while (valid == t.size()) {
//                if (right - left + 1 < minLen) {
//                    minLen = right - left + 1;
//                    minLeft = left;
//                }
//
//                // 移除s[left]从当前窗口
//                have[s[left]]--;
//                if (need.find(s[left]) != need.end() && have[s[left]] < need[s[left]]) {
//                    valid--;
//                }
//
//                left++;
//            }
//
//            right++;
//        }
//
//        // 返回最短覆盖子串
//        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
//    }
//};


class Solution {
public:
    // 找到s中包含t所有字符的最小窗口
    string minWindow(string s, string t) {
        // 初始化两个哈希表，分别用于存储s和t中字符的计数
        unordered_map<char, int> hs, ht;

        // 统计t中每个字符出现的次数
        for (int i = 0; i < t.length(); ++i) {
            ht[t[i]]++;
        }

        string ans; // 存储最小窗口的字符串
        // 初始化两个指针i和j，以及计数器cnt
        for (int i = 0, j = 0, cnt = 0; i < s.length(); ++i) {
            // 每遍历到一个字符，就将其在hs中的计数加1
            if (++hs[s[i]] <= ht[s[i]]) {
                // 如果当前字符在hs中的计数小于等于在ht中的计数，
                // 说明当前窗口可能包含t的所有字符
                cnt++;
            }

            // 尝试通过移动j指针来缩小窗口
            while (cnt == t.length() && j <= i) {
                // 如果s[j]在hs中的计数大于ht中的计数，
                // 说明当前窗口包含多余的s[j]字符，需要缩小窗口
                if (hs[s[j]] > ht[s[j]]) {
                    hs[s[j]]--;
                    j++; // 移动j指针
                }
                else {
                    // 找到满足条件的最小窗口
                    // 计算当前窗口的长度，并与ans中的窗口长度比较
                    if (ans.empty() || ans.length() > i - j + 1) {
                        ans = s.substr(j, i - j + 1);
                    }
                    break; // 找到满足条件的窗口后，退出内层循环
                }
            }
        }
        return ans; // 返回包含t所有字符的最小窗口
    }
};


int main() {
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = solution.minWindow(s, t);
    if (!result.empty()) {
        cout << "The smallest window is: " << result << endl;
    }
    else {
        cout << "No window found." << endl;
    }

    return 0;
}