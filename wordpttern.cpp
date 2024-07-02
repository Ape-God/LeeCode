#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string str, string pattern) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        int n = str.size();
        int m = pattern.size();

        if (n != m) return false; // 模式长度不同则直接返回false

        for (int i = 0; i < n; ++i) {
            string word = str.substr(i, 1); // 当前字符作为子串-
            char p = pattern[i];

            if (charToWord.count(p) == 0 && wordToChar.count(word) == 0) {
                // 如果字符和单词之间还没有映射关系，则建立映射
                charToWord[p] = word;
                wordToChar[word] = p;
            }
            else if (charToWord[p] != word || wordToChar[word] != p) {
                // 如果已有映射关系，但是不匹配，则返回false
                return false;
            }
        }

        return true; // 所有映射关系匹配成功
    }
};

int main() {
    Solution solution;
    string str = "abba";
    string pattern = "dog cat cat dog";

    bool result = solution.wordPattern(str, pattern);
    if (result) {
        cout << "The string and pattern match the word pattern." << endl;
    }
    else {
        cout << "The string and pattern do not match the word pattern." << endl;
    }

    return 0;
}