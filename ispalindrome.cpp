#include <iostream>
#include <string>
#include <cctype> // ���� tolower
#include<algorithm>

using namespace std;

//bool isPalindrome(string s) {
//    // Ԥ�����ַ������Ƴ�����ĸ�����ַ���ת��ΪСд
//    s.erase(remove_if(s.begin(), s.end(), [](char c) {
//        return !isalnum(static_cast<unsigned char>(c));
//        }), s.end());
//    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
//        return tolower(c);
//        });
//
//    // ����ַ����Ƿ��ǻ���
//    int left = 0, right = s.length() - 1;
//    while (left < right) {
//        if (s[left] != s[right]) {
//            return false; // ����ַ���ƥ�䣬���ǻ���
//        }
//        left++;
//        right--;
//    }
//    return true; // �����ַ�ƥ�䣬�ǻ���
//}

//class Solution {
//public:
//    bool isPalindrome(string s) {
//        string sgood;
//        for (char ch : s) {
//            if (isalnum(ch)) {
//                sgood += tolower(ch);
//            }
//        }
//        string sgood_rev(sgood.rbegin(), sgood.rend());
//        return sgood == sgood_rev;
//    }
//};


class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch : s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        int n = sgood.size();
        int left = 0, right = n - 1;
        while (left < right) {
            if (sgood[left] != sgood[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};


int main() {
    string s = "A man, a plan, a canal: Panama";
    Solution solution;
    bool result = solution.isPalindrome(s);
    cout << "Is \"" << s << "\" a palindrome? " << (result ? "Yes" : "No") << endl;
    return 0;
}