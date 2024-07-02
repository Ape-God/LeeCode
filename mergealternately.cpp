#include <iostream>
#include <string>
using namespace std;

string mergeAlternately(string word1, string word2) {
    int i = 0; // ���ڱ��� word1 ������
    int j = 0; // ���ڱ��� word2 ������
    string merged = ""; // ���ڴ洢�ϲ�����ַ���

    // ����� word1 �� word2 ������ַ���ֱ�������ַ����е�һ��������
    while (i < word1.size() && j < word2.size()) {
        merged.push_back(word1[i++]);
        merged.push_back(word2[j++]);
    }

    // ��� word1 ����ʣ���ַ�����������ӵ� merged ĩβ
    while (i < word1.size()) {
        merged.push_back(word1[i++]);
    }

    // ��� word2 ����ʣ���ַ�����������ӵ� merged ĩβ
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



// ���Ժ���
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