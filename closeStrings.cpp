#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> count1(26), count2(26);
        for (char c : word1) {
            count1[c - 'a']++;
        }
        for (char c : word2) {
            count2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count1[i] > 0 && count2[i] == 0 || count1[i] == 0 && count2[i] > 0) {
                return false;
            }
        }
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());
        return count1 == count2;
    }
};


// 示例函数，用于演示 Solution 类的 closeStrings 方法
int main() {
    Solution solution;
    // 创建两个示例字符串
    string word1 = "abc";
    string word2 = "bca";

    // 调用 closeStrings 方法并输出结果
    cout << "The strings \"" << word1 << "\" and \"" << word2 << "\" are "
        << (solution.closeStrings(word1, word2) ? "close" : "not close") << "." << endl;

    return 0;
}