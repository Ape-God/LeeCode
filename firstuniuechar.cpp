#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> charCount;

    // 统计每个字符的出现次数
    for (char c : s) {
        charCount[c]++;
    }

    // 找到第一个只出现一次的字符的索引
    for (int i = 0; i < s.length(); ++i) {
        if (charCount[s[i]] == 1) {
            return i; // 返回该字符的索引
        }
    }

    return -1; // 如果没有找到，返回-1
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