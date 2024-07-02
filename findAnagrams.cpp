#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // �������������ҵ�����p����λ�ʵ��Ӵ�����ʼ����
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size(); // ��ȡs��p�ĳ���

        // ���s�ĳ���С��p��ֱ�ӷ��ؿ���������Ϊ����������λ���Ӵ�
        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans; // ���ڴ洢���������
        vector<int> sCount(26, 0); // ��ʼ��s���ַ�������������a-z��ASCIIֵ
        vector<int> pCount(26, 0); // ��ʼ��p���ַ�������

        // ����p��ÿ���ַ��ļ���
        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a']; // s�еĵ�һ�������ַ�����
            ++pCount[p[i] - 'a'];
        }

        // ���s�ĵ�һ�������ַ�������p��ͬ����¼��ʼ����0
        if (sCount == pCount) {
            ans.emplace_back(0);
        }

        // �������ڣ���s�ĵڶ����ַ���ʼ
        for (int i = 0; i < sLen - pLen; ++i) {
            // �Ӵ�������Ƴ�һ���ַ��������¼���
            --sCount[s[i] - 'a'];
            // �������Ҳ�����ַ���ӵ����ڣ������¼���
            ++sCount[s[i + pLen] - 'a'];

            // ������º�Ĵ����ַ�������p��ͬ����¼��ǰ���ڵ���ʼ����
            if (sCount == pCount) {
                ans.emplace_back(i + 1);
            }
        }

        // ����������λ���Ӵ�����ʼ����
        return ans;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if (m < n) {
            return {};
        }
        vector<int> ans, sCount(26), pCount(26);
        for (auto c : p) {
            pCount[c - 'a']++;
        }
        vector<int> res;
        for (int i = 0; i < m; ++i) {
            sCount[s[i] - 'a']++;
            if (i >= n) {
                sCount[s[i - n] - 'a']--;
            }
            if (sCount == pCount) {
                res.push_back(i - n + 1);
            }
        }
        return res;
    }
};

// ʾ��������������ʾ Solution ��� findAnagrams ����
int main() {
    Solution solution;
    // ����һ��ʾ���ַ���s��ģʽ�ַ���p
    string s = "abba";
    string p = "bab";
    // ���� findAnagrams ������������
    vector<int> indices = solution.findAnagrams(s, p);
    cout << "Start indices of anagram substrings: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}