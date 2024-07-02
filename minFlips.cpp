#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // �����������ڼ�����С��ת����
    int minFlips(int a, int b, int c) {
        int ans = 0; // ��ʼ����ת�������ۼƱ���
        // �������п��ܵ�λ����0��30����Ϊint��32λ�ģ�
        for (int i = 0; i < 31; ++i) {
            // ��ȡa�ĵ�ǰλ
            int bit_a = (a >> i) & 1;
            // ��ȡb�ĵ�ǰλ
            int bit_b = (b >> i) & 1;
            // ��ȡc�ĵ�ǰλ
            int bit_c = (c >> i) & 1;

            // ���c�ĵ�ǰλ��0����ôa��b�ĵ�ǰλ���붼��0��1����ת������a��b��ǰλΪ1�ĸ���
            if (bit_c == 0) {
                ans += bit_a + bit_b;
            }
            // ���c�ĵ�ǰλ��1����ôa��b�ĵ�ǰλ����������һ����1����ת������a��b��ǰλΪ0�Ĵ���
            else {
                ans += (bit_a + bit_b == 0);
            }
        }
        return ans; // �����ܷ�ת����
    }
};

// ʾ��������������ʾ Solution ��� minFlips ����
int main() {
    Solution solution;
    // ���� minFlips ������������
    int a = 2;
    int b = 6;
    int c = 5;
    cout << "Minimum flips needed: " << solution.minFlips(a, b, c) << endl;

    return 0;
}