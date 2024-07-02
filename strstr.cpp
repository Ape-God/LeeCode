#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0; // ���needleΪ�գ��������ⷵ��0

        int len1 = haystack.size();
        int len2 = needle.size();

        // ���needle��haystack�����������ҵ�ƥ��
        if (len2 > len1) return -1;

        // ����haystack��ʹ��i��ʾ��ǰƥ�����ʼ����
        for (int i = 0; i <= len1 - len2; ++i) {
            // ����ÿ�����ܵ���ʼλ�ã�����Ƿ����ƥ��
            if (haystack.substr(i, len2) == needle) {
                return i; // �ҵ�ƥ�䣬���ص�ǰ����
            }
        }

        return -1; // û���ҵ�ƥ�������-1
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