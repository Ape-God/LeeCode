#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_set<char> vowset{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

public:
    // 主函数，用于计算长度为k的子字符串中元音字母的最大数目
    int maxVowels(string s, int k) {
        int maxCount = 0; // 初始化最大元音数
        int count = 0; // 当前窗口中元音的数目

        // 遍历字符串s，计算长度为k的窗口中的元音数目
        for (int i = 0; i < k; ++i) {
            if (vowset.find(s[i]) != vowset.end()) {
                count++; // 如果当前字符是元音，增加计数
            }
        }
        maxCount = count; // 更新最大元音数

        // 滑动窗口，从第k个字符开始
        for (int i = k; i < s.length(); ++i) {
            // 如果左侧窗口边的字符是元音，减少计数
            if (vowset.find(s[i - k]) != vowset.end()) {
                count--;
            }
            // 检查当前字符是否是元音，如果是，增加计数
            if (vowset.find(s[i]) != vowset.end()) {
                count++;
            }
            // 更新最大元音数
            maxCount = max(maxCount, count);
        }

        return maxCount; // 返回最大元音数
    }
};

// 示例函数，用于演示 Solution 类的 maxVowels 方法
int main() {
    Solution solution;
    // 创建一个示例字符串
    string s = "abciiidefggh";
    int k = 3;
    // 调用 maxVowels 方法并输出结果
    cout << "The maximum number of vowels in a substring of length " << k
        << " is: " << solution.maxVowels(s, k) << endl;

    return 0;
}