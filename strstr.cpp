#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0; // 如果needle为空，根据题意返回0

        int len1 = haystack.size();
        int len2 = needle.size();

        // 如果needle比haystack长，不可能找到匹配
        if (len2 > len1) return -1;

        // 遍历haystack，使用i表示当前匹配的起始索引
        for (int i = 0; i <= len1 - len2; ++i) {
            // 对于每个可能的起始位置，检查是否存在匹配
            if (haystack.substr(i, len2) == needle) {
                return i; // 找到匹配，返回当前索引
            }
        }

        return -1; // 没有找到匹配项，返回-1
    }
};

int main() {
    Solution solution;
    std::string haystack = "hello";
    std::string needle = "ll";
    int index = solution.strStr(haystack, needle);

    if (index != -1) {
        std::cout << "First match found at index: " << index << std::endl;
    }
    else {
        std::cout << "No match found." << std::endl;
    }

    return 0;
}