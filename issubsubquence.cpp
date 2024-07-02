#include <string>
#include <iostream>
using namespace std;

//class Solution {
//public:
//    bool isSubsequence(std::string s, std::string t) {
//        int sIndex = 0, tIndex = 0; // ��ʼ�������ַ���������
//
//        // �����ַ��� t
//        while (tIndex < t.size()) {
//            // �����ǰ�ַ�ƥ�䣬sIndex ��ǰ�ƶ�
//            if (sIndex < s.size() && s[sIndex] == t[tIndex]) {
//                sIndex++;
//            }
//            // ������Σ�tIndex ��Ҫ��ǰ�ƶ�
//            tIndex++;
//        }
//
//        // ��� sIndex ���� s ��ĩβ��˵�� s �� t ��������
//        return sIndex == s.size();
//    }
//};

class Solution {
public:
    // �������������ж��ַ��� s �Ƿ����ַ��� t ��������
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size(); // �ֱ��ȡ s �� t �ĳ���
        int i = 0, j = 0; // ��ʼ�� s �� t ������

        // ʹ�� while ѭ������ s �� t ��δ����ĩβʱ�������
        while (i < n && j < m) {
            // �����ǰ s ���ַ��� t ���ַ���ͬ
            if (s[i] == t[j]) {
                i++; // s �����������ƶ�һλ
            }
            j++; // t ������ʼ�������ƶ�һλ
        }

        // ��� s ������ i ����ĩβ��˵�� s �е������ַ����� t �а�˳�������
        return i == n;
    }
};



int main() {
    Solution solution;
    std::string s = "axc";
    std::string t = "ahbgdc";

    bool isSubsequence = solution.isSubsequence(s, t);
    std::cout << (isSubsequence ? "s is a subsequence of t" : "s is not a subsequence of t") << std::endl;
    return 0;
}