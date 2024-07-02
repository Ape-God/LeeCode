#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    // ��������������ַ��� t �Ƿ����ַ��� s �������ظ�
    bool check(string t, string s) {
        int lenx = s.length() / t.length(); // ���� s ���Ա� t �ظ����ٴ�
        string ans = ""; // ��ʼ������ַ���
        // �ظ� t��ֱ���ﵽ s �ĳ���
        for (int i = 1; i <= lenx; ++i) {
            ans = ans + t;
        }
        // ���������ַ��� ans ���� s���򷵻� true
        return ans == s;
    }

    // �������������ҳ������ַ�������󹫹��ظ�����
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length(); // ��ȡ�����ַ����ĳ���
        // ʹ�� std::gcd ���������ַ������ȵ����Լ��
        string T = str1.substr(0, __gcd(len1, len2));
        // ��� T �Ƿ��� str1 �� str2 �������ظ�����
        if (check(T, str1) && check(T, str2)) {
            // ����ǣ��� T �������ַ����Ĺ����ظ����У����� T
            return T;
        }
        // ���û���ҵ������ظ����У����ؿ��ַ���
        return "";
    }
};

//class Solution {
//    bool check(string t, string s) {
//        int lenx = (int)s.length() / (int)t.length();
//        string ans = "";
//        for (int i = 1; i <= lenx; ++i) {
//            ans = ans + t;
//        }
//        return ans == s;
//    }
//public:
//    string gcdOfStrings(string str1, string str2) {
//        int len1 = (int)str1.length(), len2 = (int)str2.length();
//        string T = str1.substr(0, __gcd(len1, len2)); // __gcd() Ϊc++�Դ��������Լ���ĺ���
//        if (check(T, str1) && check(T, str2)) return T;
//        return "";
//    }
//};


int main() {
    Solution solution;
    string str1 = "ABCABC", str2 = "ABC";
    string result = solution.gcdOfStrings("ABCABC", "ABC");

    cout << "The greatest common divisor of '" << str1 << "' and '" << str2 << "' is: " << result << endl;

    return 0;
}