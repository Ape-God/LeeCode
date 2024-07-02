#include <iostream>
#include <string>
#include <unordered_map>
#include<algorithm>
using namespace std;

//bool isAnagram(std::string s, std::string t) {
//    // 如果长度不同，直接返回 false
//    if (s.length() != t.length()) {
//        return false;
//    }
//
//    std::unordered_map<char, int> char_count;
//
//    // 统计字符串 s 中每个字符的出现次数
//    for (char c : s) {
//        char_count[c]++;
//    }
//
//    // 检查字符串 t 中的字符是否与 s 中的字符计数匹配
//    for (char c : t) {
//        if (char_count.find(c) == char_count.end() || char_count[c] == 0) {
//            return false; // 如果字符 c 在 s 中没有出现，或者出现次数为 0，则不是字母异位词
//        }
//        char_count[c]--;
//    }
//
//    return true; // 所有字符计数都匹配，则 t 是 s 的字母异位词
//}


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};



int main() {
    std::string s = "anagram";
    std::string t = "nagaram";
    Solution solution;
    bool result = solution.isAnagram(s, t);
    std::cout << (result ? "true" : "false") << std::endl; // 应该输出 true
    return 0;
}