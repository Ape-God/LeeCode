#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
private:
    // 定义一个字符集合，包含所有大小写的元音字母
    unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A','E','I', 'O','U' };
public:
    // 主函数，用于反转字符串 s 中的元音字母
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1; // 初始化左右指针
        // 使用 while 循环，当左指针小于右指针时继续执行
        while (left < right) {
            // 使用 while 循环找到左侧第一个元音字母
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++; // 如果当前字符不是元音，则左指针右移
            }
            // 使用 while 循环找到右侧第一个元音字母
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--; // 如果当前字符不是元音，则右指针左移
            }
            // 交换左右指针所指向的元音字母
            swap(s[left], s[right]);
            // 移动指针，继续查找下一对元音字母
            left++;
            right--;
        }
        // 返回反转元音字母后的字符串
        return s;
    }
};

// 测试函数
void testSolution(Solution& solution, string& s) {
    string result = solution.reverseVowels(s);
    cout << "Reversed vowels: " << result << endl;
}

int main() {
    Solution solution;
    string s1 = "hello";
    testSolution(solution, s1);

    string s2 = "leetcode";
    testSolution(solution, s2);

    return 0;
}