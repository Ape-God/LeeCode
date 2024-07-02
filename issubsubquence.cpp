#include <string>
#include <iostream>
using namespace std;

//class Solution {
//public:
//    bool isSubsequence(std::string s, std::string t) {
//        int sIndex = 0, tIndex = 0; // 初始化两个字符串的索引
//
//        // 遍历字符串 t
//        while (tIndex < t.size()) {
//            // 如果当前字符匹配，sIndex 向前移动
//            if (sIndex < s.size() && s[sIndex] == t[tIndex]) {
//                sIndex++;
//            }
//            // 无论如何，tIndex 都要向前移动
//            tIndex++;
//        }
//
//        // 如果 sIndex 到达 s 的末尾，说明 s 是 t 的子序列
//        return sIndex == s.size();
//    }
//};

class Solution {
public:
    // 主函数，用于判断字符串 s 是否是字符串 t 的子序列
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size(); // 分别获取 s 和 t 的长度
        int i = 0, j = 0; // 初始化 s 和 t 的索引

        // 使用 while 循环，当 s 和 t 都未到达末尾时继续检查
        while (i < n && j < m) {
            // 如果当前 s 的字符与 t 的字符相同
            if (s[i] == t[j]) {
                i++; // s 的索引向右移动一位
            }
            j++; // t 的索引始终向右移动一位
        }

        // 如果 s 的索引 i 到达末尾，说明 s 中的所有字符都在 t 中按顺序出现了
        return i == n;
    }
};



int main() {
    Solution solution;
    std::string s = "axc";
    std::string t = "ahbgdc";

    bool isSubsequence = solution.isSubsequence(s, t);
    std::cout << (isSubsequence ? "s is a subsequence of t" : "s is not a subsequence of t") << std::endl;
    return 0;
}