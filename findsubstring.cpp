#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string& s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int m = words.size(), n = words[0].size(), ls = s.size();
        // 检查每个单词的长度乘以单词数量是否超过字符串长度
        if (m * n > ls) return res;

        // 使用 unordered_map 存储每个单词出现的次数
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            if (word.length() != n) return res; // 所有单词长度必须一致
            wordCount[word]++;
        }

        // 遍历字符串 s，寻找可能的子串起始位置
        for (int i = 0; i <= ls - m * n; ++i) {
            unordered_map<string, int> differ(wordCount); // 当前子串单词计数
            int j = 0; // words 中单词的索引

            // 尝试匹配 words 中的每个单词
            while (j < m) {
                string word = s.substr(i + j * n, n);
                if (differ.find(word) == differ.end() || --differ[word] < 0) {
                    break;
                }
                j++;
            }
            // 如果找到了匹配的子串
            if (j == m) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = "barfoothefoobarman";
    vector<string> words = { "foo", "bar" };
    vector<int> result = solution.findSubstring(s, words);

    if (!result.empty()) {
        cout << "The starting indices of the shortest substrings containing all words are: ";
        for (int idx : result) {
            cout << idx << " ";
        }
        cout << endl;
    }
    else {
        cout << "No substring found that contains all words." << endl;
    }

    return 0;
}