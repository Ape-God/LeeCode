#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> charCount;

    // ͳ��ÿ���ַ��ĳ��ִ���
    for (char c : s) {
        charCount[c]++;
    }

    // �ҵ���һ��ֻ����һ�ε��ַ�������
    for (int i = 0; i < s.length(); ++i) {
        if (charCount[s[i]] == 1) {
            return i; // ���ظ��ַ�������
        }
    }

    return -1; // ���û���ҵ�������-1
}

int main() {
    string s = "leetcode";
    int index = firstUniqChar(s);
    if (index != -1) {
        cout << "The first unique character is at index: " << index << endl;
    }
    else {
        cout << "There is no unique character in the string." << endl;
    }
    return 0;
}