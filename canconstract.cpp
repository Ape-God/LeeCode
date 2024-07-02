#include <iostream>
#include <string>
#include <unordered_map>

bool canConstruct(std::string ransomNote, std::string magazine) {
    std::unordered_map<char, int> char_count;

    // ͳ��magazine��ÿ���ַ��ĳ��ִ���
    for (char c : magazine) {
        char_count[c]++;
    }

    // ���������е�ÿ���ַ�
    for (char c : ransomNote) {
        if (char_count.find(c) == char_count.end() || char_count[c] == 0) {
            // ����ַ�����magazine�л��������㣬�򷵻�false
            return false;
        }
        // ���ٸ��ַ���magazine�еļ���
        char_count[c]--;
    }

    // ��������ַ������㹻���������򷵻�true
    return true;
}

int main() {
    std::string ransomNote = "aa";
    std::string magazine = "ab";
    bool result = canConstruct(ransomNote, magazine);
    std::cout << (result ? "true" : "false") << std::endl; // Ӧ����� false
    return 0;
}