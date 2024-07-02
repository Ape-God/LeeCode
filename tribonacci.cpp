#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // �����������ڼ���� n ��̩��������
    int tribonacci(int n) {
        // ������������ n Ϊ 0������ 0
        if (n == 0) {
            return 0;
        }
        // ������������ n Ϊ 1 �� 2������ 1
        if (n <= 2) {
            return 1;
        }

        // ��ʼ��ǰ����̩��������
        int p = 0, q = 0, r = 1, s = 1; // p, q, r ���ڵ������㣬s �洢��ǰ��̩��������
        for (int i = 3; i <= n; ++i) {
            // ͨ����������� i ��̩��������
            // ��ǰ��������ǰ�ƶ��������µ�̩���������������
            p = q; // p �洢 T(i-2) ��ֵ
            q = r; // q �洢 T(i-1) ��ֵ
            r = s; // r �洢 T(i-0) ��ֵ
            s = p + q + r; // s ���� T(i) ��ֵ
        }

        // ���ص� n ��̩��������
        return s;
    }
};


// ʾ��������������ʾ Solution ��� tribonacci ����
int main() {
    Solution solution;
    // ���� tribonacci ������������
    for (int i = 0; i < 10; ++i) { // ����ǰ 10 ��̩��������
        cout << "The 5th tribonacci number is: " << solution.tribonacci(i) << endl;
    }

    return 0;
}