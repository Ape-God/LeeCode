#include <iostream>
#include <cmath>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0; // 0 ��ƽ������ 0

        long long start = 1, end = x; // ��ʼ����������
        while (start <= end) { // ʹ�� while ѭ�����ж��ֲ���
            long long mid = start + (end - start) / 2; // �����м�ֵ
            long long square = mid * mid; // �����м�ֵ��ƽ��

            if (square == x) {
                return mid; // �����ȫƽ�������ؽ��
            }
            else if (square < x) {
                start = mid + 1; // ���ƽ��С�� x�������½�
            }
            else {
                end = mid - 1; // ���ƽ������ x�������Ͻ�
            }
        }

        return end; // ���� end ���ܴ���ʵ��ƽ���������ؽ�С��������
    }
};

int main() {
    Solution solution;
    int x = 4;
    int result = solution.mySqrt(x);

    std::cout << "The square root of " << x << " is: " << result << std::endl;

    return 0;
}