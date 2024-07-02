#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include<iostream>

using namespace std;

class Solution {
public:
    // �����������ڷ�ת�ַ��� s �����е��ʵ�˳��
    string reverseWords(string s) {
        // ���ȣ���ת�����ַ���
        reverse(s.begin(), s.end());

        int n = s.size(); // ��ȡ�ַ����ĳ���
        int idx = 0; // ��ʼ�����������ڹ�����ת���ʺ���ַ���

        // �����ַ���
        for (int start = 0; start < n; ++start) {
            // �ҵ����ʵ���ʼλ��
            if (s[start] != ' ') {
                // ���idx��Ϊ0����ʾǰ���Ѿ��з�ת�ĵ��ʣ������ڵ�ǰ����ǰ��һ���ո�
                if (idx != 0) {
                    s[idx++] = ' ';
                }

                // �ҵ���ǰ���ʵĽ���λ��
                int end = start;
                while (end < n && s[end] != ' ') {
                    // ����ǰ���ʸ��Ƶ�s��ǰ�棬ʵ�ַ�ת����
                    s[idx++] = s[end++];
                }
                // ��ת�ոո��Ƶĵ��ʣ��Ա��ֵ����ڲ��ַ���˳��
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                // ����start��λ�ã�������������
                start = end;
            }
        }

        // �Ƴ��ַ���β���Ŀո�����еĻ���
        s.erase(s.begin() + idx, s.end());

        // ���ط�ת����˳�����ַ���
        return s;
    }
};


//class Solution {
//public:
//    string reverseWords(string s) {
//        // ȥ���ַ������˵Ŀհ��ַ�
//        s.erase(0, s.find_first_not_of(' ')); // ȥ��ǰ���հ�
//        s.erase(s.find_last_not_of(' ') + 1); // ȥ��β��հ�
//
//        vector<string> words;
//        size_t i = 0, j = 0;
//
//        // ʹ��˫ָ���ҵ����ʵ���ʼ�ͽ���λ��
//        while (i < s.length()) {
//            // ����ǰ���ո�
//            while (i < s.length() && isspace(s[i])) {
//                i++;
//            }
//            j = i;
//            // �ƶ� i ֱ�������ո���ַ�������
//            while (i < s.length() && !isspace(s[i])) {
//                i++;
//            }
//            // ��ȡ����
//            words.push_back(s.substr(j, i - j));
//        }
//
//        // ��ת��������
//        reverse(words.begin(), words.end());
//
//        // ƴ�ӵ���������ַ���
//        string result;
//        for (const string& word : words) {
//            result += word;
//            // �������һ�������⣬��ÿ�����ʺ���ӿո�
//            if (&word != &words.back()) {
//                result += ' ';
//            }
//        }
//        return result;
//    }
//};


int main() {
    Solution solution;
    string s = " the sky is blue";

    string reversedString = solution.reverseWords(s);
    cout << "Reversed string: \"" << reversedString << "\"" << endl;

    return 0;
}