#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // 如果数组为空，返回空字符串

        string prefix = strs[0]; // 以数组的第一个字符串作为初始前缀
        for (const string& str : strs) {
            while (str.find(prefix) != 0) { // 只要prefix不是str的前缀
                prefix = prefix.substr(0, prefix.length() - 1); // 缩短prefix
                if (prefix.empty()) return ""; // 如果前缀为空，没有公共前缀
            }
        }
        return prefix; // 返回找到的最长公共前缀
    }
};

int main() {
    Solution solution;
    vector<string> strs = { "flower","flow","flight" };

    string result = solution.longestCommonPrefix(strs);
    if (!result.empty()) {
        cout << "The longest common prefix is: " << result << endl;
    }
    else {
        cout << "There is no common prefix." << endl;
    }

    return 0;
}