#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    string minWindow(string s, string t) {
//        unordered_map<char, int> need, have;
//        // ��¼t��ÿ���ַ����ֵĴ���
//        for (char c : t) {
//            need[c]++;
//        }
//
//        int left = 0, right = 0;
//        int valid = 0; // ��ʾ��ǰ�����������������ַ���
//        int minLen = INT_MAX, minLeft = 0;
//        string res;
//
//        while (right < s.size()) {
//            // ���s[right]����ǰ����
//            have[s[right]]++;
//            if (need.find(s[right]) != need.end() && have[s[right]] <= need[s[right]]) {
//                valid++;
//            }
//
//            // ������С����ֱ����ǰ���ڲ�����������
//            while (valid == t.size()) {
//                if (right - left + 1 < minLen) {
//                    minLen = right - left + 1;
//                    minLeft = left;
//                }
//
//                // �Ƴ�s[left]�ӵ�ǰ����
//                have[s[left]]--;
//                if (need.find(s[left]) != need.end() && have[s[left]] < need[s[left]]) {
//                    valid--;
//                }
//
//                left++;
//            }
//
//            right++;
//        }
//
//        // ������̸����Ӵ�
//        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
//    }
//};


class Solution {
public:
    // �ҵ�s�а���t�����ַ�����С����
    string minWindow(string s, string t) {
        // ��ʼ��������ϣ���ֱ����ڴ洢s��t���ַ��ļ���
        unordered_map<char, int> hs, ht;

        // ͳ��t��ÿ���ַ����ֵĴ���
        for (int i = 0; i < t.length(); ++i) {
            ht[t[i]]++;
        }

        string ans; // �洢��С���ڵ��ַ���
        // ��ʼ������ָ��i��j���Լ�������cnt
        for (int i = 0, j = 0, cnt = 0; i < s.length(); ++i) {
            // ÿ������һ���ַ����ͽ�����hs�еļ�����1
            if (++hs[s[i]] <= ht[s[i]]) {
                // �����ǰ�ַ���hs�еļ���С�ڵ�����ht�еļ�����
                // ˵����ǰ���ڿ��ܰ���t�������ַ�
                cnt++;
            }

            // ����ͨ���ƶ�jָ������С����
            while (cnt == t.length() && j <= i) {
                // ���s[j]��hs�еļ�������ht�еļ�����
                // ˵����ǰ���ڰ��������s[j]�ַ�����Ҫ��С����
                if (hs[s[j]] > ht[s[j]]) {
                    hs[s[j]]--;
                    j++; // �ƶ�jָ��
                }
                else {
                    // �ҵ�������������С����
                    // ���㵱ǰ���ڵĳ��ȣ�����ans�еĴ��ڳ��ȱȽ�
                    if (ans.empty() || ans.length() > i - j + 1) {
                        ans = s.substr(j, i - j + 1);
                    }
                    break; // �ҵ����������Ĵ��ں��˳��ڲ�ѭ��
                }
            }
        }
        return ans; // ���ذ���t�����ַ�����С����
    }
};


int main() {
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = solution.minWindow(s, t);
    if (!result.empty()) {
        cout << "The smallest window is: " << result << endl;
    }
    else {
        cout << "No window found." << endl;
    }

    return 0;
}