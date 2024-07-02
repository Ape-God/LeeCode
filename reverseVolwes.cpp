#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
private:
    // ����һ���ַ����ϣ��������д�Сд��Ԫ����ĸ
    unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A','E','I', 'O','U' };
public:
    // �����������ڷ�ת�ַ��� s �е�Ԫ����ĸ
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1; // ��ʼ������ָ��
        // ʹ�� while ѭ��������ָ��С����ָ��ʱ����ִ��
        while (left < right) {
            // ʹ�� while ѭ���ҵ�����һ��Ԫ����ĸ
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++; // �����ǰ�ַ�����Ԫ��������ָ������
            }
            // ʹ�� while ѭ���ҵ��Ҳ��һ��Ԫ����ĸ
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--; // �����ǰ�ַ�����Ԫ��������ָ������
            }
            // ��������ָ����ָ���Ԫ����ĸ
            swap(s[left], s[right]);
            // �ƶ�ָ�룬����������һ��Ԫ����ĸ
            left++;
            right--;
        }
        // ���ط�תԪ����ĸ����ַ���
        return s;
    }
};

// ���Ժ���
void testSolution(Solution& solution, string& s) {
    string result = solution.reverseVowels(s);
    cout << "Reversed vowels: " << result << endl;
}

int main() {
    Solution solution;
    string s1 = "hello";
    testSolution(solution, s1);

    string s2 = "leetcode";
    testSolution(solution, s2);

    return 0;
}