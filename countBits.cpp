#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    // �����������ڼ���ÿ�����ֵĶ����Ʊ�ʾ��1�ĸ���
    vector<int> countBits(int n) {
        vector<int> ans(n + 1); // ����һ������Ϊ n + 1 ������
        for (int i = 0; i <= n; ++i) {
            ans[i] = bitsCount(i); // �������� i �Ķ����Ʊ�ʾ��1�ĸ���
        }
        return ans; // ��������
    }

private:
    // �������������ڼ���һ�����ֵĶ����Ʊ�ʾ��1�ĸ���
    int bitsCount(int num) {
        int count = 0; // ��ʼ��������
        while (num > 0) { // �����ִ���0ʱ
            count += num & 1; // �����ǰ���λ��1����������1
            num >>= 1; // ����������һλ
        }
        return count; // ���ؼ�������ֵ
    }
};

// ʾ��������������ʾ Solution ��� countBits ����
int main() {
    Solution solution;
    // ���� countBits ������������
    int n = 5;
    vector<int> ans = solution.countBits(n);
    cout << "Bits count for numbers 0 to " << n << " is: ";
    for (int i = 0; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}