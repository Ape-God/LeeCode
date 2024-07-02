#include <iostream>
#include <string>
#include <unordered_map>

bool canConstruct(std::string ransomNote, std::string magazine) {
    std::unordered_map<char, int> char_count;

    // 统计magazine中每个字符的出现次数
    for (char c : magazine) {
        char_count[c]++;
    }

    // 检查赎金信中的每个字符
    for (char c : ransomNote) {
        if (char_count.find(c) == char_count.end() || char_count[c] == 0) {
            // 如果字符不在magazine中或数量不足，则返回false
            return false;
        }
        // 减少该字符在magazine中的计数
        char_count[c]--;
    }

    // 如果所有字符都有足够的数量，则返回true
    return true;
}

int main() {
    std::string ransomNote = "aa";
    std::string magazine = "ab";
    bool result = canConstruct(ransomNote, magazine);
    std::cout << (result ? "true" : "false") << std::endl; // 应该输出 false
    return 0;
}