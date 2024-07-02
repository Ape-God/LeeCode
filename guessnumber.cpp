#include <iostream>
using namespace std;

// ��������Ԥ�ȶ���õĽӿ�
int guess(int num) {
    // ������ģ��ʵ�֣�ʵ�ʵ�ʵ�ֻ������Ϸ�Ĺ��򷵻�-1, 1, �� 0
    int picked = 42; // ������ȷ����42
    if (num == picked) {
        return 0;
    }
    else if (num > picked) {
        return -1;
    }
    else {
        return 1;
    }
}

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) { // ѭ��ֱ���������Ҷ˵���ͬ
            int mid = left + (right - left) / 2; // ��ֹ����ʱ���
            if (guess(mid) <= 0) {
                right = mid; // �������� [left, mid] ��
            }
            else {
                left = mid + 1; // �������� [mid+1, right] ��
            }
        }
        // ��ʱ�� left == right��������Ϊһ���㣬��Ϊ��
        return left;
    }
};


// ���Ժ���
void testSolution(Solution& solution, int n) {
    int result = solution.guessNumber(n);
    cout << "The picked number is: " << result << endl;
}

int main() {
    Solution solution;
    int n = 100; // ����nΪ100
    testSolution(solution, n);

    return 0;
}