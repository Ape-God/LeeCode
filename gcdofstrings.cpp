#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    // 辅助函数，检查字符串 t 是否是字符串 s 的连续重复
    bool check(string t, string s) {
        int lenx = s.length() / t.length(); // 计算 s 可以被 t 重复多少次
        string ans = ""; // 初始化结果字符串
        // 重复 t，直到达到 s 的长度
        for (int i = 1; i <= lenx; ++i) {
            ans = ans + t;
        }
        // 如果构造的字符串 ans 等于 s，则返回 true
        return ans == s;
    }

    // 主函数，用于找出两个字符串的最大公共重复序列
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length(); // 获取两个字符串的长度
        // 使用 std::gcd 计算两个字符串长度的最大公约数
        string T = str1.substr(0, __gcd(len1, len2));
        // 检查 T 是否是 str1 和 str2 的连续重复序列
        if (check(T, str1) && check(T, str2)) {
            // 如果是，则 T 是两个字符串的公共重复序列，返回 T
            return T;
        }
        // 如果没有找到公共重复序列，返回空字符串
        return "";
    }
};

//class Solution {
//    bool check(string t, string s) {
//        int lenx = (int)s.length() / (int)t.length();
//        string ans = "";
//        for (int i = 1; i <= lenx; ++i) {
//            ans = ans + t;
//        }
//        return ans == s;
//    }
//public:
//    string gcdOfStrings(string str1, string str2) {
//        int len1 = (int)str1.length(), len2 = (int)str2.length();
//        string T = str1.substr(0, __gcd(len1, len2)); // __gcd() 为c++自带的求最大公约数的函数
//        if (check(T, str1) && check(T, str2)) return T;
//        return "";
//    }
//};


int main() {
    Solution solution;
    string str1 = "ABCABC", str2 = "ABC";
    string result = solution.gcdOfStrings("ABCABC", "ABC");

    cout << "The greatest common divisor of '" << str1 << "' and '" << str2 << "' is: " << result << endl;

    return 0;
}