#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//class Solution {
//public:
//    // ���Ĵ��ָ��
//    void backtrack(int start, string s, vector<string>& current, vector<vector<string>>& result) {
//        if (start == s.size()) {
//            // ����Ѿ������ַ���ĩβ������ǰ�ָ����ӵ������
//            result.push_back(current);
//            return;
//        }
//
//        for (int end = start; end < s.size(); ++end) {
//            // ����� start �� end ���Ӵ��ǻ��Ĵ�
//            if (isPalindrome(s, start, end)) {
//                // ���Ӵ���ӵ���ǰ�ָ����
//                current.push_back(s.substr(start, end - start + 1));
//                // �����ݹ鴦�������ַ���
//                backtrack(end + 1, s, current, result);
//                // ���ݣ��Ƴ���ǰ�Ӵ������������ָ��
//                current.pop_back();
//            }
//        }
//    }
//
//    // �ж��Ƿ��ǻ��Ĵ��ĸ�������
//    bool isPalindrome(const string& s, int start, int end) {
//        while (start < end) {
//            if (s[start++] != s[end--]) {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    // �����ķָ���Ĵ�����
//    vector<vector<string>> partition(string s) {
//        vector<vector<string>> result; // �洢���п��ܵķָ��
//        vector<string> current; // �洢��ǰ�ķָ��
//        backtrack(0, s, current, result); // �ӵ�һ���ַ���ʼ�ݹ�
//        return result;
//    }
//};


class Solution {
private:
    vector<vector<int>> f;  // f[i][j] ���ڴ洢 s[i...j] �Ƿ�Ϊ���Ĵ�
    vector<vector<string>> ret;  // �洢���п��ܵķָ��
    vector<string> ans;  // �洢��ǰ�ķָ��
    int n;  // �ַ��� s �ĳ���

public:
    // ����������������������ҳ����п��ܵķָ��
    void dfs(const string& s, int i) {
        if (i == n) {  // ����Ѿ������ַ���ĩβ
            ret.push_back(ans);  // ����ǰ�ָ����ӵ������
            return;
        }
        // ���Դ� i ��ʼ�����п��ܵĻ����Ӵ�
        for (int j = i; j < n; ++j) {
            if (f[i][j]) {  // ��� s[i...j] �ǻ��Ĵ�
                ans.push_back(s.substr(i, j - i + 1));  // ���Ӵ���ӵ���ǰ�ָ��
                dfs(s, j + 1);  // �ݹ鴦�������ַ���
                ans.pop_back();  // ���ݣ��Ƴ���ǰ�Ӵ������������ָ��
            }
        }
    }

    // �����ķָ���Ĵ�����
    vector<vector<string>> partition(string s) {
        n = s.size();  // ����ַ�������
        f.assign(n, vector<int>(n, true));  // ��ʼ�� f�����Ϊ true

        // ���� f��f[i][j] ��ʾ s[i...j] �Ƿ�Ϊ���Ĵ�
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        dfs(s, 0);  // �ӵ�һ���ַ���ʼ�ݹ�
        return ret;  // �������п��ܵķָ��
    }
};



// ʾ������
int main() {
    Solution solution;
    string s1 = "aab";
    vector<vector<string>> result1 = solution.partition(s1);
    // ��ӡ���ʾ��1
    for (const auto& part : result1) {
        for (const auto& str : part) {
            cout << str << " ";
        }
        cout << endl;
    }

    string s2 = "a";
    vector<vector<string>> result2 = solution.partition(s2);
    // ��ӡ���ʾ��2
    for (const auto& part : result2) {
        for (const auto& str : part) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}