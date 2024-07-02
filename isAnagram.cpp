#include <iostream>
#include <string>
#include <unordered_map>
#include<algorithm>
using namespace std;

//bool isAnagram(std::string s, std::string t) {
//    // ������Ȳ�ͬ��ֱ�ӷ��� false
//    if (s.length() != t.length()) {
//        return false;
//    }
//
//    std::unordered_map<char, int> char_count;
//
//    // ͳ���ַ��� s ��ÿ���ַ��ĳ��ִ���
//    for (char c : s) {
//        char_count[c]++;
//    }
//
//    // ����ַ��� t �е��ַ��Ƿ��� s �е��ַ�����ƥ��
//    for (char c : t) {
//        if (char_count.find(c) == char_count.end() || char_count[c] == 0) {
//            return false; // ����ַ� c �� s ��û�г��֣����߳��ִ���Ϊ 0��������ĸ��λ��
//        }
//        char_count[c]--;
//    }
//
//    return true; // �����ַ�������ƥ�䣬�� t �� s ����ĸ��λ��
//}


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};



int main() {
    std::string s = "anagram";
    std::string t = "nagaram";
    Solution solution;
    bool result = solution.isAnagram(s, t);
    std::cout << (result ? "true" : "false") << std::endl; // Ӧ����� true
    return 0;
}