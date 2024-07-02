#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_set<char> vowset{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

public:
    // �����������ڼ��㳤��Ϊk�����ַ�����Ԫ����ĸ�������Ŀ
    int maxVowels(string s, int k) {
        int maxCount = 0; // ��ʼ�����Ԫ����
        int count = 0; // ��ǰ������Ԫ������Ŀ

        // �����ַ���s�����㳤��Ϊk�Ĵ����е�Ԫ����Ŀ
        for (int i = 0; i < k; ++i) {
            if (vowset.find(s[i]) != vowset.end()) {
                count++; // �����ǰ�ַ���Ԫ�������Ӽ���
            }
        }
        maxCount = count; // �������Ԫ����

        // �������ڣ��ӵ�k���ַ���ʼ
        for (int i = k; i < s.length(); ++i) {
            // �����ര�ڱߵ��ַ���Ԫ�������ټ���
            if (vowset.find(s[i - k]) != vowset.end()) {
                count--;
            }
            // ��鵱ǰ�ַ��Ƿ���Ԫ��������ǣ����Ӽ���
            if (vowset.find(s[i]) != vowset.end()) {
                count++;
            }
            // �������Ԫ����
            maxCount = max(maxCount, count);
        }

        return maxCount; // �������Ԫ����
    }
};

// ʾ��������������ʾ Solution ��� maxVowels ����
int main() {
    Solution solution;
    // ����һ��ʾ���ַ���
    string s = "abciiidefggh";
    int k = 3;
    // ���� maxVowels ������������
    cout << "The maximum number of vowels in a substring of length " << k
        << " is: " << solution.maxVowels(s, k) << endl;

    return 0;
}