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
        // ���ÿ�����ʵĳ��ȳ��Ե��������Ƿ񳬹��ַ�������
        if (m * n > ls) return res;

        // ʹ�� unordered_map �洢ÿ�����ʳ��ֵĴ���
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            if (word.length() != n) return res; // ���е��ʳ��ȱ���һ��
            wordCount[word]++;
        }

        // �����ַ��� s��Ѱ�ҿ��ܵ��Ӵ���ʼλ��
        for (int i = 0; i <= ls - m * n; ++i) {
            unordered_map<string, int> differ(wordCount); // ��ǰ�Ӵ����ʼ���
            int j = 0; // words �е��ʵ�����

            // ����ƥ�� words �е�ÿ������
            while (j < m) {
                string word = s.substr(i + j * n, n);
                if (differ.find(word) == differ.end() || --differ[word] < 0) {
                    break;
                }
                j++;
            }
            // ����ҵ���ƥ����Ӵ�
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