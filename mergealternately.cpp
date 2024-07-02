#include <iostream>
#include <string>
using namespace std;

string mergeAlternately(string word1, string word2) {
    int i = 0; // 用于遍历 word1 的索引
    int j = 0; // 用于遍历 word2 的索引
    string merged = ""; // 用于存储合并后的字符串

    // 交替从 word1 和 word2 中添加字符，直到两个字符串中的一个遍历完
    while (i < word1.size() && j < word2.size()) {
        merged.push_back(word1[i++]);
        merged.push_back(word2[j++]);
    }

    // 如果 word1 还有剩余字符，将它们添加到 merged 末尾
    while (i < word1.size()) {
        merged.push_back(word1[i++]);
    }

    // 如果 word2 还有剩余字符，将它们添加到 merged 末尾
    while (j < word2.size()) {
        merged.push_back(word2[j++]);
    }

    return merged;
}


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int i = 0, j = 0;

        string ans;
        ans.reserve(m + n);
        while (i < m || j < n) {
            if (i < m) {
                ans.push_back(word1[i]);
                ++i;
            }
            if (j < n) {
                ans.push_back(word2[j]);
                ++j;
            }
        }
        return ans;
    }
};



// 测试函数
void testMergeAlternately(const string& word1, const string& word2) {
    string result = mergeAlternately(word1, word2);
    cout << "Merged string: " << result << endl;
}

int main() {
    string word1 = "abc";
    string word2 = "pqr";
    Solution solution;
    string result = solution.mergeAlternately(word1, word2);
    cout << "Merged string: " << result << endl;

    testMergeAlternately(word1, word2);

    word1 = "abcd";
    word2 = "pq";
    testMergeAlternately(word1, word2);

    return 0;
}