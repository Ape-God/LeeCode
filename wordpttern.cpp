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

        if (n != m) return false; // ģʽ���Ȳ�ͬ��ֱ�ӷ���false

        for (int i = 0; i < n; ++i) {
            string word = str.substr(i, 1); // ��ǰ�ַ���Ϊ�Ӵ�-
            char p = pattern[i];

            if (charToWord.count(p) == 0 && wordToChar.count(word) == 0) {
                // ����ַ��͵���֮�仹û��ӳ���ϵ������ӳ��
                charToWord[p] = word;
                wordToChar[word] = p;
            }
            else if (charToWord[p] != word || wordToChar[word] != p) {
                // �������ӳ���ϵ�����ǲ�ƥ�䣬�򷵻�false
                return false;
            }
        }

        return true; // ����ӳ���ϵƥ��ɹ�
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