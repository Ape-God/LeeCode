#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        // 从字符串的末尾开始遍历
        int index = s.size() - 1;
        while (s[index] == ' ') {
            index--;
        }
        while (index >0 && s[index] < s.size()-1) {
            length++;
            index--;
        }

        //for (int i = s.size() - 1; i >= 0; --i) {
        //    // 当遇到非空格字符时，开始计数单词长度
        //    if (s[i] != ' ') {
        //        length++;
        //    }
        //    // 如果遇到空格，且已经计数了单词长度，则停止计数
        //    else if (length > 0) {
        //        break;
        //    }
        //}
        return length;
    }
};

int main() {
    Solution solution;
    string s = "Hello World";

    int result = solution.lengthOfLastWord(s);
    cout << "The length of the last word is: " << result << endl;

    return 0;
}