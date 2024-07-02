#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include<iostream>

using namespace std;

class Solution {
public:
    // 主函数，用于反转字符串 s 中所有单词的顺序
    string reverseWords(string s) {
        // 首先，反转整个字符串
        reverse(s.begin(), s.end());

        int n = s.size(); // 获取字符串的长度
        int idx = 0; // 初始化索引，用于构建反转单词后的字符串

        // 遍历字符串
        for (int start = 0; start < n; ++start) {
            // 找到单词的起始位置
            if (s[start] != ' ') {
                // 如果idx不为0，表示前面已经有反转的单词，所以在当前单词前加一个空格
                if (idx != 0) {
                    s[idx++] = ' ';
                }

                // 找到当前单词的结束位置
                int end = start;
                while (end < n && s[end] != ' ') {
                    // 将当前单词复制到s的前面，实现反转单词
                    s[idx++] = s[end++];
                }
                // 反转刚刚复制的单词，以保持单词内部字符的顺序
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                // 更新start的位置，跳过整个单词
                start = end;
            }
        }

        // 移除字符串尾部的空格（如果有的话）
        s.erase(s.begin() + idx, s.end());

        // 返回反转单词顺序后的字符串
        return s;
    }
};


//class Solution {
//public:
//    string reverseWords(string s) {
//        // 去除字符串两端的空白字符
//        s.erase(0, s.find_first_not_of(' ')); // 去除前导空白
//        s.erase(s.find_last_not_of(' ') + 1); // 去除尾随空白
//
//        vector<string> words;
//        size_t i = 0, j = 0;
//
//        // 使用双指针找到单词的起始和结束位置
//        while (i < s.length()) {
//            // 跳过前导空格
//            while (i < s.length() && isspace(s[i])) {
//                i++;
//            }
//            j = i;
//            // 移动 i 直到遇到空格或字符串结束
//            while (i < s.length() && !isspace(s[i])) {
//                i++;
//            }
//            // 提取单词
//            words.push_back(s.substr(j, i - j));
//        }
//
//        // 反转单词数组
//        reverse(words.begin(), words.end());
//
//        // 拼接单词数组成字符串
//        string result;
//        for (const string& word : words) {
//            result += word;
//            // 除了最后一个单词外，在每个单词后添加空格
//            if (&word != &words.back()) {
//                result += ' ';
//            }
//        }
//        return result;
//    }
//};


int main() {
    Solution solution;
    string s = " the sky is blue";

    string reversedString = solution.reverseWords(s);
    cout << "Reversed string: \"" << reversedString << "\"" << endl;

    return 0;
}